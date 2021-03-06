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

package com.intel.rsa.podm.business.entities.assets;

import com.intel.rsa.common.utils.IterableHelper;
import com.intel.rsa.podm.business.entities.assets.links.CollectionLink;
import com.intel.rsa.podm.business.entities.base.DomainObject;
import com.intel.rsa.podm.business.entities.base.DomainObjectProperty;

import javax.enterprise.context.Dependent;
import javax.transaction.Transactional;
import java.util.List;

import static com.intel.rsa.podm.business.entities.base.DomainObjectProperties.integerProperty;
import static com.intel.rsa.podm.business.entities.base.DomainObjectProperties.listProperty;
import static com.intel.rsa.podm.business.entities.base.DomainObjectProperties.stringProperty;

@Dependent
@Transactional(Transactional.TxType.REQUIRED)
public class RemoteTargetIscsiAddress extends DomainObject {

    public static final DomainObjectProperty<List<Integer>> TARGET_LUN = listProperty("targetLun");
    public static final DomainObjectProperty<String> TARGET_IQN = stringProperty("targetIqn");
    public static final DomainObjectProperty<String> TARGET_PORTAL_IP = stringProperty("targetPortalIp");
    public static final DomainObjectProperty<Integer> TARGET_PORTAL_PORT = integerProperty("targetPortalPort");

    public List<Integer> getTargetLun() {
        return getProperty(TARGET_LUN);
    }

    public void setTargetLun(List<Integer> targetLun) {
        setProperty(TARGET_LUN, targetLun);
    }

    public String getTargetIqn() {
        return getProperty(TARGET_IQN);
    }

    public void setTargetIqn(String targetIqn) {
        setProperty(TARGET_IQN, targetIqn);
    }

    public String getTargetPortalIp() {
        return getProperty(TARGET_PORTAL_IP);
    }

    public void setTargetPortalIp(String targetPortalIp) {
        setProperty(TARGET_PORTAL_IP, targetPortalIp);
    }

    public Integer getTargetPortalPort() {
        return getProperty(TARGET_PORTAL_PORT);
    }

    public void setTargetPortalPort(int targetPortalPort) {
        setProperty(TARGET_PORTAL_PORT, targetPortalPort);
    }

    public RemoteTarget getRemoteTarget() {
        return IterableHelper.single(getLinked(CollectionLink.COLLECTED_BY, RemoteTarget.class));
    }
}
