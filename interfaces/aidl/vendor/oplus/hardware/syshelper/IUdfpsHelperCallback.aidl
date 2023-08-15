package vendor.oplus.hardware.syshelper;

@VintfStability
interface IUdfpsHelperCallback {
    void onUdfpsTouchStatusChanged(boolean isDown);
}
