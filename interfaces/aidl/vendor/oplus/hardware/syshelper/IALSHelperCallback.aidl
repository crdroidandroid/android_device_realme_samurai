package vendor.oplus.hardware.syshelper;

import vendor.oplus.hardware.syshelper.ScreenShotInfo;

@VintfStability
interface IALSHelperCallback {
    ScreenShotInfo takeScreenShot();
}
