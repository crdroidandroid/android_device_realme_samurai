/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "FingerprintInscreenService"

#include "FingerprintInscreen.h"
#include <hidl/HidlTransportSupport.h>
#include <android-base/logging.h>
#include <fstream>
#include <unistd.h>
#include <cmath>
#include <thread>

#define FINGERPRINT_ACQUIRED_VENDOR 6

/* Hardcoded stuffs */
#define AOD_LIGHT_MODE_PATH "/sys/kernel/oppo_display/aod_light_mode_set"
#define DC_DIM_PATH "/sys/kernel/oppo_display/dimlayer_bl_en"
#define DIMLAYER_PATH "/sys/kernel/oppo_display/dimlayer_hbm"
#define DOZE_STATUS "/proc/touchpanel/DOZE_STATUS"
#define FP_ENABLE_PATH "/proc/touchpanel/fp_enable"
#define FP_PRESS_PATH "/sys/kernel/oppo_display/notify_fppress"
#define PANEL_BLANK_PATH "/sys/kernel/oppo_display/notify_panel_blank"

#define X_POS 445
#define Y_POS 2061
#define FP_SIZE 190

#define FP_BEGIN 1
#define FP_ENDIT 0

bool dcDimState;

namespace {

template <typename T>
static void set(const std::string& path, const T& value) {
    std::ofstream file(path);
    file << value;
    LOG(INFO) << "wrote path: " << path << ", value: " << value << "\n";
}

template <typename T>
static T get(const std::string& path, const T& def) {
    std::ifstream file(path);
    T result;

    file >> result;
    return file.fail() ? def : result;
}

} // anonymous namespace

namespace vendor {
namespace lineage {
namespace biometrics {
namespace fingerprint {
namespace inscreen {
namespace V1_0 {
namespace implementation {

FingerprintInscreen::FingerprintInscreen()
    : isDreamState{false} {
    this->mFodCircleVisible = false;
}

Return<int32_t> FingerprintInscreen::getPositionX() {
    return X_POS;
}

Return<int32_t> FingerprintInscreen::getPositionY() {
    return Y_POS;
}

Return<int32_t> FingerprintInscreen::getSize() {
    return FP_SIZE;
}

Return<void> FingerprintInscreen::onStartEnroll() {
    return Void();
}

Return<void> FingerprintInscreen::onFinishEnroll() {
    return Void();
}

Return<void> FingerprintInscreen::onPress() {
    if(isDreamState) {
    set(DIMLAYER_PATH, FP_BEGIN);
    std::thread([this]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
        set(FP_PRESS_PATH, FP_BEGIN);
        set(AOD_LIGHT_MODE_PATH, FP_BEGIN);
    }).detach();
    }
    if(get(DOZE_STATUS, FP_BEGIN) && get(FP_ENABLE_PATH, FP_BEGIN)) {
    set(FP_ENABLE_PATH, FP_ENDIT);
    set(FP_ENABLE_PATH, FP_BEGIN);
    }
    return Void();
}

Return<void> FingerprintInscreen::onRelease() {
    if(isDreamState)
    set(DIMLAYER_PATH, FP_ENDIT);
    set(AOD_LIGHT_MODE_PATH, FP_ENDIT);
    return Void();
}

Return<void> FingerprintInscreen::onShowFODView() {
    if (!mFodCircleVisible) {
        dcDimState = get(DC_DIM_PATH, FP_ENDIT);
        set(DC_DIM_PATH, FP_ENDIT);
    }
    if(get(DOZE_STATUS, FP_ENDIT)) {
    isDreamState = true;
    set(PANEL_BLANK_PATH, FP_BEGIN);
    } else {
    isDreamState = false;
    set(DIMLAYER_PATH, FP_BEGIN);
    }
    return Void();
}

Return<void> FingerprintInscreen::onHideFODView() {
    if (mFodCircleVisible) {
        set(DC_DIM_PATH, dcDimState);
    }
    if(!isDreamState)
    set(DIMLAYER_PATH, FP_ENDIT);
    return Void();
}

Return<bool> FingerprintInscreen::handleAcquired(int32_t acquiredInfo, int32_t vendorCode) {
    std::lock_guard<std::mutex> _lock(mCallbackLock);
    if (mCallback == nullptr) {
        return false;
    }

    if (acquiredInfo == FINGERPRINT_ACQUIRED_VENDOR) {
        if (mFodCircleVisible && vendorCode == 1) {
            Return<void> ret = mCallback->onFingerDown();
            if (!ret.isOk()) {
                LOG(ERROR) << "FingerDown() error: " << ret.description();
            }
            return true;
        }

        if (mFodCircleVisible && vendorCode == 0) {
            Return<void> ret = mCallback->onFingerUp();
            if (!ret.isOk()) {
                LOG(ERROR) << "FingerUp() error: " << ret.description();
            }
            return true;
        }
    }

    return false;
}

Return<bool> FingerprintInscreen::handleError(int32_t error, int32_t vendorCode) {
    LOG(ERROR) << "error: " << error << ", vendorCode: " << vendorCode << "\n";
    return false;
}

Return<void> FingerprintInscreen::setLongPressEnabled(bool) {
    return Void();
}

Return<int32_t> FingerprintInscreen::getDimAmount(int32_t) {
    return 0;
}

Return<bool> FingerprintInscreen::shouldBoostBrightness() {
    return false;
}

Return<void> FingerprintInscreen::setCallback(const sp<::vendor::lineage::biometrics::fingerprint::inscreen::V1_0::IFingerprintInscreenCallback>& callback) {
    {
        std::lock_guard<std::mutex> _lock(mCallbackLock);
        mCallback = callback;
    }
    return Void();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace inscreen
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace lineage
}  // namespace vendor
