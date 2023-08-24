#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>

#include "ALSHelper.h"

using aidl::vendor::oplus::hardware::syshelper::ALSHelper;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(10);
    std::shared_ptr<ALSHelper> alsHelper = ndk::SharedRefBase::make<ALSHelper>();

    std::string instance = std::string() + ALSHelper::descriptor + "/default";
    binder_status_t status =
        AServiceManager_addService(alsHelper->asBinder().get(), instance.c_str());
    CHECK_EQ(status, STATUS_OK);

    LOG(INFO) << "Oplus SysHelper Registered!";

    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE;  // Unreachable
}
