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
*/

#include "agent-framework/eventing/event_client.hpp"
#include "agent-framework/logger_loader.hpp"
#include "logger/logger_factory.hpp"
#include "agent-framework/module/module.hpp"
#include "agent-framework/module/module_manager.hpp"
#include "agent-framework/registration/registration_data.hpp"
#include "agent-framework/registration/registration_manager.hpp"
#include "agent-framework/signal.hpp"
#include "agent-framework/state_machine/state_machine.hpp"
#include "agent-framework/state_machine/state_machine_thread.hpp"

#include "agent-framework/command/command.hpp"
#include "agent-framework/command/command_factory.hpp"
#include "agent-framework/command/command_json.hpp"
#include "agent-framework/command/command_json_server.hpp"
#include "agent-framework/command/compute/get_components.hpp"

#include "discovery/discovery_manager.hpp"

#include "configuration/configuration.hpp"
#include "default_configuration.hpp"

#include <jsonrpccpp/server/connectors/httpserver.h>

#include <csignal>
#include <cstdio>
#include <memory>

using namespace std;
using namespace agent_framework;
using namespace agent_framework::generic;
using namespace logger_cpp;
using namespace configuration;

using command::Command;
using command::CommandFactory;
using command::CommandJson;
using command::CommandJsonServer;
using command::compute::GetComponents;

using agent::generic::DEFAULT_CONFIGURATION;
using agent::generic::DEFAULT_ENV_FILE;
using agent::generic::DEFAULT_FILE;

static constexpr unsigned int DEFAULT_SERVER_PORT = 7777;

/*!
 * @brief Generic Agent main method.
 * */
int main(int argc, char* argv[]) {
    unsigned int server_port = DEFAULT_SERVER_PORT;

    StateMachineThreadUniquePtr state_machine_thread_u_ptr = nullptr;
    EventClientUniquePtr client = nullptr;

    /* Initialize configuration */
    auto& basic_config = Configuration::get_instance();
    basic_config.set_default_configuration(DEFAULT_CONFIGURATION);
    basic_config.set_default_file(DEFAULT_FILE);
    basic_config.set_default_env_file(DEFAULT_ENV_FILE);
    /* @TODO This should be replaced with nice arguments parsing class */
    while (argc > 1) {
        basic_config.add_file(argv[argc - 1]);
        --argc;
    }
    basic_config.load_key_file();
    const json::Value& configuration = basic_config.to_json();

    /* Initialize logger */
    LoggerLoader loader(configuration);
    LoggerFactory::instance().set_loggers(loader.load());
    LoggerFactory::set_main_logger_name("agent");
    log_info(GET_LOGGER("compute-agent"), "Running Generic Agent...\n");

    try {
        server_port = configuration["server"]["port"].as_uint();
    } catch (const json::Value::Exception& e) {
        log_error(GET_LOGGER("compute-agent"),
                "Cannot read server port " << e.what());
    }

    RegistrationManager reg_manager;
    RegistrationData reg_data;

    agent::compute::discovery::DiscoveryManager discovery_manager;

    /* Register */
    reg_manager.register_agent(reg_data);

    /* Initialize command server */
    auto& commands_factory = CommandFactory::get_instance();
    commands_factory.add_commands(configuration);
    auto commands_initialization =
        commands_factory.create_initialization();
    auto commands = commands_factory.create();

    jsonrpc::HttpServer http_server((int(server_port)));
    CommandJsonServer server(http_server);

    server.add(commands);
    server.start();

    try {
        /* Create modules */
        ModuleManager::create();
        /* Start state machine */
        state_machine_thread_u_ptr.reset(
                new StateMachineThread(ModuleManager::get_modules(),
                discovery_manager));
        /* Start RPC Client */

        client.reset(new EventClient(reg_data));

        state_machine_thread_u_ptr->subscribe(client.get());

        state_machine_thread_u_ptr->start();
        client->start();
    }
    catch (exception & e) {
        log_error(GET_LOGGER("compute-agent"), e.what());
    }

    /* Stop the program and wait for interrupt */
    wait_for_interrupt();

    server.stop();

    log_info(GET_LOGGER("compute-agent"), "Stopping Generic Agent...\n");

    /* Cleanup */
    commands_initialization.clear();
    ModuleManager::cleanup();
    command::Command::Map::cleanup();
    command::CommandJson::Map::cleanup();
    command::CommandFactory::cleanup();
    Configuration::cleanup();
    LoggerFactory::cleanup();

    return 0;
}
