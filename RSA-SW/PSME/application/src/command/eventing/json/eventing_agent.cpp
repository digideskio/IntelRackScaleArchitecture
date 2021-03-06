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
 *
 * @file command/eventing/json/eventing_agent.cpp
 *
 * @brief JSON command EventingAgent implementation
 * */

#include "eventing_agent.hpp"
#include "command/eventing/eventing_agent.hpp"
#include "logger/logger_factory.hpp"
#include <iostream>

using namespace psme;
using namespace psme::command::eventing::json;

EventingAgent::EventingAgent() :
    CommandJson(eventing::TAG, Procedure(
                eventing::EventingAgent::TAG,
                jsonrpc::PARAMS_BY_NAME,
                "id", jsonrpc::JSON_STRING,
                "newState", jsonrpc::JSON_STRING,
                "transition", jsonrpc::JSON_STRING,
                nullptr)) {
    }

void EventingAgent::method(const Json::Value& params, Json::Value& result) {
    (void) params;
    (void) result;
}

void EventingAgent::notification(const Json::Value& params) {
    try {
        Command* command = get_command();

        eventing::EventingAgent::Request request{};
        eventing::EventingAgent::Response response{};

        request.m_gami_id = params["gamiId"].asString();
        request.m_id = params["id"].asString();
        request.m_state = params["newState"].asString();
        request.m_transition = params["transition"].asString();

        command->execute(request, response);

    } catch (const command::exception::NotFound&) {
        log_error(LOGUSR, "-32602 Component not found");
        /* @TODO: Move common exceptions to JSON command server */
        throw jsonrpc::JsonRpcException(-32602, "Component not found");
    } catch (...) {
        log_error(LOGUSR, "-1 JSON command error");
        throw jsonrpc::JsonRpcException(-1, "JSON command error");
    }
}

static CommandJson::Register<EventingAgent> g;
