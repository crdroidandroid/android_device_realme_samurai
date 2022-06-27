/*
 * Copyright (C) 2020 LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <vector>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "property_service.h"
#include "vendor_init.h"

using android::base::ReadFileToString;
using android::base::Trim;

std::vector<std::string> ro_props_default_source_order = {
    "",
    "odm.",
    "product.",
    "system.",
    "vendor.",
    "vendor_dlkm.",
};

void property_override(char const prop[], char const value[], bool add = true)
{
    prop_info *pi;
    pi = (prop_info *)__system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else if (add)
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    const auto set_ro_product_prop = [](const std::string &source,
            const std::string &prop, const std::string &value) {
        auto prop_name = "ro.product." + source + prop;
        property_override(prop_name.c_str(), value.c_str(), false);
    };

    char const *operator_name_file = "/proc/oppoVersion/operatorName";
    std::string operator_name;

    if (ReadFileToString(operator_name_file, &operator_name)) {
        /* GLOBAL */
        if ((Trim(operator_name) == "5")) {
           for (const auto &source : ro_props_default_source_order) {
               set_ro_product_prop(source, "device", "RMX1931L1");
           }
        /* CHINA */
        } else if ((Trim(operator_name) == "8")) {
           for (const auto &source : ro_props_default_source_order) {
               set_ro_product_prop(source, "device", "RMX1931CN");
           }
        } else {
        LOG(ERROR) << "Unsupported variant";
        }
    }
}
