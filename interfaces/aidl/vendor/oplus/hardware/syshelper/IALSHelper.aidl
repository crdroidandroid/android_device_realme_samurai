package vendor.oplus.hardware.syshelper;

import vendor.oplus.hardware.syshelper.IALSHelperCallback;
import vendor.oplus.hardware.syshelper.ScreenShotInfo;

@VintfStability
interface IALSHelper {
    ScreenShotInfo takeScreenShot();
    void registerCallback(in IALSHelperCallback callback);
    void unregisterCallback(in IALSHelperCallback callback);
}
