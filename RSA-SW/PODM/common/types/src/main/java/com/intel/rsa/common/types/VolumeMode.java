/*
 * Copyright (c) 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.intel.rsa.common.types;

/**
 * Mode of volume.
 */
public enum VolumeMode implements ConvertableEnum {
    JBOD("JBOD"),
    BLOCK_DEVICE("BlockDevice"),
    LOGICAL_DRIVE("LogicalDrive"),
    PV("PV"),
    LV("LV"),
    LVG("LVG"),
    OSD("OSD"),
    POOL("Pool"),
    RAID0("RAID0"),
    RAID1("RAID1"),
    RAID10("RAID10"),
    RAID5("RAID5"),
    RAID6("RAID6"),
    RAID50("RAID50"),
    RAID60("RAID60");

    private String value;

    VolumeMode(String value) {
        this.value = value;
    }

    @Override
    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return getValue();
    }
}
