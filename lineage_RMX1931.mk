#
# Copyright (C) 2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

$(call inherit-product, device/realme/RMX1931/device.mk)

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_BRAND := realme
PRODUCT_DEVICE := RMX1931
PRODUCT_MANUFACTURER := realme
PRODUCT_MODEL := realme X2 Pro
PRODUCT_NAME := lineage_RMX1931

BUILD_FINGERPRINT := "realme/RMX1931/RMX1931L1:10/QKQ1.191021.002/1594708134:user/release-keys"

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="RMX1931-user 10 QKQ1.191021.002 1594708134 release-keys" \
    PRODUCT_NAME="RMX1931"

PRODUCT_GMS_CLIENTID_BASE := android-realme
