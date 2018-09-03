#
# Copyright (C) 2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Dalvik
PRODUCT_PRODUCT_PROPERTIES += \
    dalvik.vm.heapstartsize=32m \
    dalvik.vm.heapgrowthlimit=512m \
    dalvik.vm.heapsize=768m \
    dalvik.vm.heaptargetutilization=0.5 \
    dalvik.vm.heapminfree=8m \
    dalvik.vm.heapmaxfree=64m

# Google Assistant
PRODUCT_PRODUCT_PROPERTIES += \
    ro.opa.eligible_device=true

# Graphics
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    ro.surface_flinger.vsync_event_phase_offset_ns=2000000 \
    ro.surface_flinger.vsync_sf_event_phase_offset_ns=6000000

# gsi
PRODUCT_PRODUCT_PROPERTIES += \
    ro.vendor.gsi.build.flavor=none

# Media
PRODUCT_PRODUCT_PROPERTIES += \
    debug.stagefright.omx_default_rank.sw-audio=16
