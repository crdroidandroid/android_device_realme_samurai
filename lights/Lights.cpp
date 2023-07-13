/*
 * Copyright (C) 2019 The Android Open Source Project
 * Copyright (C) 2020-2021 The LineageOS Project
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

#define LOG_TAG "android.hardware.lights-service_samurai"

#include "Lights.h"
#include <android-base/file.h>
#include <android-base/logging.h>
#include <fstream>

namespace {

/*
 * Write value to path and close file.
 */
template <typename T>
static void set(const std::string& path, const T& value) {
    std::ofstream file(path);
    file << value;
}

template <typename T>
static T get(const std::string& path, const T& def) {
    std::ifstream file(path);
    T result;

    file >> result;
    return file.fail() ? def : result;
}

static int rgbToBrightness(const aidl::android::hardware::light::HwLightState& state) {
    int color = state.color & 0x00ffffff;
    return ((77 * ((color >> 16) & 0x00ff))
            + (150 * ((color >> 8) & 0x00ff))
            + (29 * (color & 0x00ff))) >> 8;
}

}  // anonymous namespace

namespace aidl {
namespace android {
namespace hardware {
namespace light {

Lights::Lights() {
    std::map<int, std::function<void(int id, const HwLightState&)>> lights_{
            {(int)LightType::BACKLIGHT, {}}};

    std::vector<HwLight> availableLights;
    for (auto const& pair : lights_) {
        int id = pair.first;
        HwLight hwLight{};
        hwLight.id = id;
        availableLights.emplace_back(hwLight);
    }
    mAvailableLights = availableLights;
    mLights = lights_;
}

ndk::ScopedAStatus Lights::setLightState(int id, const HwLightState& state) {
    auto it = mLights.find(id);
    if (it == mLights.end()) {
        LOG(ERROR) << "Light not supported";
        return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
    }

    it->second(id, state);

    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus Lights::getLights(std::vector<HwLight>* lights) {
    for (auto i = mAvailableLights.begin(); i != mAvailableLights.end(); i++) {
        lights->push_back(*i);
    }
    return ndk::ScopedAStatus::ok();
}

void Lights::handleBacklight(const HwLightState& state) {
    int maxBrightness = get("/sys/class/backlight/panel0-backlight/max_brightness", -1);
        if (maxBrightness < 0) {
            maxBrightness = 2047;
        }

    int sentBrightness = rgbToBrightness(state);
    int brightness = sentBrightness * 1023 / 255;
        LOG(DEBUG) << "Writing backlight brightness " << brightness
                   << " (orig " << sentBrightness << ")";
        set("/sys/class/backlight/panel0-backlight/brightness", brightness);
}

}  // namespace light
}  // namespace hardware
}  // namespace android
}  // namespace aidl
