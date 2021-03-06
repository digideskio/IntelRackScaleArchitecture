/*!
 * @section LICENSE
 *
 * @copyright
 * Copyright (c) 2015 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @section DESCRIPTION
 * */

#include "agent-framework/command/network/delete_port_vlan.hpp"
#include "agent-framework/module/module_manager.hpp"
#include "api/switch_vlan.hpp"
#include "api/ies/switch_vlan.hpp"

using namespace agent_framework::command;
using namespace agent_framework::generic;

namespace agent {
namespace network {
namespace hw {
namespace fm6000 {

using namespace agent_framework;

class DeletePortVlan : public command::network::DeletePortVlan {

public:
    DeletePortVlan() { }

    using agent_framework::command::network::DeletePortVlan::execute;

    void execute(const Request& request, Response& response) {
#ifdef IES_FOUND
        const auto& uuid = request.get_component();
        const auto& port_identifier = request.get_port_identifier();
        const auto& vlan_identifier = request.get_vlan_identifier();
        try {
            api::ies::SwitchVlan vlan(uuid, vlan_identifier);
            vlan.remove_port(port_identifier);
        }
        catch (runtime_error& error) {
            log_error(GET_LOGGER("fm6000"), "Cannot delete port to vlan");
            log_debug(GET_LOGGER("fm6000"), error.what());
            throw exception::NotFound();
        }
#else
        (void) request;
#endif
        response.set_oem({});
    }

    ~DeletePortVlan();
};

DeletePortVlan::~DeletePortVlan() { }

}
}
}
}
static Command::Register<agent::network::hw::fm6000::DeletePortVlan> g("fm6000");
