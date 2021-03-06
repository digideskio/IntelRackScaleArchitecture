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

package com.intel.rsa.podm.rest.representation.json.serializers;

import com.intel.rsa.podm.business.dto.DrawerDto;
import com.intel.rsa.podm.rest.odataid.ODataIds;
import com.intel.rsa.podm.rest.representation.json.templates.DrawerJson;

import java.util.stream.Collectors;

import static com.intel.rsa.podm.business.services.context.ContextType.COMPUTE_MODULE;
import static com.intel.rsa.podm.business.services.context.ContextType.FABRIC_MODULE;
import static com.intel.rsa.podm.rest.odataid.ODataId.oDataId;
import static com.intel.rsa.podm.rest.odataid.ODataIds.oDataIdOfCollectionInContext;
import static java.net.URI.create;

public class DrawerDtoJsonSerializer extends DtoJsonSerializer<DrawerDto> {
    public DrawerDtoJsonSerializer() {
        super(DrawerDto.class);
    }

    @Override
    protected DrawerJson translate(DrawerDto dto) {
        DrawerJson result = new DrawerJson();

        result.oDataContext = create("/rest/v1/$metadata#RSADrawers/Links/Members/$entity");
        result.oDataId = oDataId(context.getRequestPath());

        result.id = dto.getId();
        result.name = dto.getName();
        result.location = toJson(dto.getLocation());
        result.modified = dto.getModified();
        result.manufacturer = dto.getManufacturer();
        result.model = dto.getModel();
        result.serialNumber = dto.getSerialNumber();

        mapStatus(dto, result);
        result.enumStatus = dto.getEnumStatus();
        result.links.fabricModules = oDataIdOfCollectionInContext(dto.getContext(), FABRIC_MODULE);
        result.links.computeModules = oDataIdOfCollectionInContext(dto.getContext(), COMPUTE_MODULE);

        result.links.managedBy.addAll(dto.getManagedBy().stream()
                .map(ODataIds::oDataIdFromContext)
                .collect(Collectors.toList()));

        return result;
    }

    private void mapStatus(DrawerDto dto, DrawerJson result) {
        result.status.state = dto.getState();
        result.status.health = dto.getHealth();
        result.status.healthRollup = dto.getHealthRollup();
    }

}
