package vendor.oplus.hardware.syshelper;

import vendor.oplus.hardware.syshelper.IUdfpsHelperCallback;

@VintfStability
interface IUdfpsHelper {
    void touchDown();
    void touchUp();
    boolean getTouchStatus();
    void registerCallback(in IUdfpsHelperCallback callback);
    void unregisterCallback(in IUdfpsHelperCallback callback);
}
