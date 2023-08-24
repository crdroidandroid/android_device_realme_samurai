#include <ALSHelper.h>
#include <android-base/logging.h>

namespace aidl {
namespace vendor {
namespace oplus {
namespace hardware {
namespace syshelper {

::ndk::ScopedAStatus ALSHelper::takeScreenShot(::aidl::vendor::oplus::hardware::syshelper::ScreenShotInfo* _aidl_return) {
    LOG(VERBOSE) << "in takeScreenShot";
    if (callback_ == nullptr) {
        return ndk::ScopedAStatus::fromExceptionCode(EX_NULL_POINTER);
    }
    ScreenShotInfo info;
    callback_->takeScreenShot(&info);
    LOG(VERBOSE) << info.toString();
    *_aidl_return = info;
    return ndk::ScopedAStatus::ok();
};

}  // namespace syshelper
}  // namespace hardware
}  // namespace oplus
}  // namespace vendor
}  // namespace aidl
