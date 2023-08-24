#pragma once

#include <aidl/vendor/oplus/hardware/syshelper/BnALSHelper.h>
#include <aidl/vendor/oplus/hardware/syshelper/IALSHelperCallback.h>
#include <aidl/vendor/oplus/hardware/syshelper/ScreenShotInfo.h>

#include <mutex>

namespace aidl {
namespace vendor {
namespace oplus {
namespace hardware {
namespace syshelper {

class ALSHelper : public BnALSHelper {
   public:
    ::ndk::ScopedAStatus takeScreenShot(::aidl::vendor::oplus::hardware::syshelper::ScreenShotInfo* _aidl_return) override;
    ::ndk::ScopedAStatus registerCallback(const std::shared_ptr<::aidl::vendor::oplus::hardware::syshelper::IALSHelperCallback>& in_callback) override {
        unregisterCallback(in_callback);
        callback_ = std::move(in_callback);
        return ::ndk::ScopedAStatus::ok();
    };
    ::ndk::ScopedAStatus unregisterCallback(const std::shared_ptr<::aidl::vendor::oplus::hardware::syshelper::IALSHelperCallback>& /*in_callback*/) override {
        callback_ = nullptr;
        return ::ndk::ScopedAStatus::ok();
    };

   private:
    std::mutex callback_mutex_lock;
    std::shared_ptr<::aidl::vendor::oplus::hardware::syshelper::IALSHelperCallback> callback_;
};

}  // namespace syshelper
}  // namespace hardware
}  // namespace oplus
}  // namespace vendor
}  // namespace aidl
