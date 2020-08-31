# Audio
PRODUCT_PROPERTY_OVERRIDES += \
    ro.config.media_vol_steps=25 \
    ro.config.vc_call_vol_steps=7

# Bluetooth
PRODUCT_PROPERTY_OVERRIDES += \
    bt.max.hfpclient.connections=1 \
    persist.bluetooth.bqr.event_mask=0x8000000E \
    persist.bluetooth.bqr.min_interval_ms=60000 \
    persist.bluetooth.bqr.choppy_threshold=9,6 \
    persist.bluetooth.disableabsvol=false \
    persist.bluetooth.disableinbandringing=false \
    persist.bluetooth.specificatcmdsenable=true \
    persist.vendor.bluetooth.a2dp.hal.implementation=true \
    persist.vendor.bluetooth.modem_nv_support=true \
    persist.vendor.bt.a2dp.hal.implementation=true \
    persist.vendor.bt.a2dp.aac_whitelist=false \
    persist.vendor.btstack.enable.splita2dp=true \
    persist.vendor.btstack.enable.twsplus=true \
    persist.vendor.btstack.enable.twsplussho=true \
    persist.vendor.service.bdroid.soc.alwayson=true \
    persist.vendor.service.bt.iot.enablelogging=true \
    persist.vendor.service.bt.iotinfo.report.enable=true \
    ro.bluetooth.a2dp_offload.supported=true \
    ro.bluetooth.library_name=libbluetooth_qti.so \
    qcom.bluetooth.soc=cherokee \
    vendor.bluetooth.soc=cherokee

# Camera
PRODUCT_PROPERTY_OVERRIDES += \
    ro.camera.hfr.enable=1 \
    ro.camera.relight.enable=0 \
    ro.camera.attr.detect.enable=1 \
    ro.camera.temperature.limit=470 \
    persist.vendor.camera.light_ae.enable=1 \
    vendor.camera.aux.packagelist=org.codeaurora.snapcam,com.android.camera,org.lineageos.snap

# CNE
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.cne.feature=1 \
    persist.cne.subscription_aware=false

# Data modules
PRODUCT_PROPERTY_OVERRIDES += \
    persist.data.netmgrd.qos.enable=true \
    persist.vendor.data.profile_update=true \
    persist.vendor.data.mode=concurrent \
    ro.vendor.use_data_netmgrd=true

# Fingerprint
PRODUCT_PROPERTY_OVERRIDES += \
    ro.boot.realme.lockstate=0

# Graphics
PRODUCT_PROPERTY_OVERRIDES += \
    debug.sf.disable_backpressure=1 \
    debug.sf.early_phase_offset_ns=500000 \
    debug.sf.early_app_phase_offset_ns=500000 \
    debug.sf.early_gl_phase_offset_ns=3000000 \
    debug.sf.early_gl_app_phase_offset_ns=15000000 \
    debug.sf.enable_gl_backpressure=1 \
    debug.sf.enable_hwc_vds=1 \
    debug.sf.latch_unsignaled=1 \
    debug.sf.high_fps_early_phase_offset_ns=6100000 \
    debug.sf.high_fps_early_gl_phase_offset_ns=9000000 \
    debug.sf.phase_offset_threshold_for_next_vsync_ns=6100000 \
    dev.pm.dyn_samplingrate=1 \
    persist.front.skipdisplay.enable=1 \
    ro.vendor.display.sensortype=2 \
    ro.vendor.display.ad.sdr_calib_data=/vendor/etc/OPPO_OLED_AD_calib.cfg

# IOP
PRODUCT_PROPERTY_OVERRIDES += \
    vendor.iop.enable_prefetch_ofr=0 \
    vendor.iop.enable_uxe=0

# Media
PRODUCT_PROPERTY_OVERRIDES += \
    media.settings.xml=/system/etc/media_profiles_vendor.xml \
    media.stagefright.thumbnail.prefer_hw_codecs=true \
    persist.mm.enable.prefetch=true \
    vendor.media.vpp.enable=true

# Memory optimizations
PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.qti.sys.fw.bservice_enable=true

# Netflix custom property
PRODUCT_PROPERTY_OVERRIDES += \
    ro.netflix.bsp_rev=Q855-16947-1

# NFC
PRODUCT_PROPERTY_OVERRIDES += \
    persist.sys.nfc.aid_overflow=true \
    persist.sys.nfc.antenna_area=bottom \
    persist.sys.nfc.default=on \
    ro.nfc.port=I2C \
    ro.product.cuptsm=OPPO|ESE|01|02

# RCS and IMS
PRODUCT_PROPERTY_OVERRIDES += \
    persist.dbg.ims_volte_enable=1 \
    persist.dbg.wfc_avail_ovr=1 \
    persist.dbg.volte_avail_ovr=1 \
    persist.dbg.vt_avail_ovr=1 \
    persist.rcs.supported=0 \
    persist.vendor.ims.disableQXDMLogs=0 \
    persist.vendor.ims.disableADBLogs=0 \
    persist.vendor.ims.disableDebugLogs=0 \
    persist.vendor.ims.disableIMSLogs=0 \
    persist.vendor.ims.rtp.enableqxdm=3 \
    persist.vendor.ims.vt.enableadb=3 \
    persit.radio.VT_LOG_LEVEL=255 \
    persist.vendor.ims.loglevel=255

# RIL
PRODUCT_PROPERTY_OVERRIDES += \
    DEVICE_PROVISIONED=1 \
    persist.radio.hvolte.enable=1 \
    persist.radio.custom_exp_ecc=1 \
    persist.sys.fflag.override.settings_network_and_internet_v2=true \
    persist.vendor.radio.atfwd.start=true \
    persist.vendor.radio.data_con_rprt=1 \
    persist.vendor.radio.lte_vrte_ltd=1 \
    persist.vendor.radio.cs_srv_type=1 \
    persist.vendor.radio.process_sups_ind=1 \
    persist.vendor.radio.rat_on=combine \
    ril.subscription.types=NV,RUIM \
    ro.telephony.default_network=22,22 \
    telephony.lteOnCdmaDevice=1

# Sensors
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.sensors.enable.mag_filter=true \
    ro.qti.sensors.wu=false

# SSR
PRODUCT_PROPERTY_OVERRIDES += \
    persist.vendor.ssr.enable_ramdumps=0 \
    persist.vendor.ssr.restart_level=ALL_ENABLE

# IWLAN
PRODUCT_PROPERTY_OVERRIDES += \
    persist.data.iwlan.enable=true \
    persist.data.iwlan.rekey=4294967295

# Zygote
PRODUCT_PROPERTY_OVERRIDES += \
    persist.device_config.runtime_native.usap_pool_enabled=true
