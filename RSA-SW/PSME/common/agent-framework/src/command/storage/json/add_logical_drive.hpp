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
 * @file command/storage/json/add_logical_drive.hpp
 *
 * @brief JSON command AddLogicalDrive
 * */

#ifndef AGENT_FRAMEWORK_COMMAND_STORAGE_JSON_ADD_LOGICAL_DRIVE_HPP
#define AGENT_FRAMEWORK_COMMAND_STORAGE_JSON_ADD_LOGICAL_DRIVE_HPP

#include "agent-framework/command/command_json.hpp"
#include "agent-framework/command/storage/add_logical_drive.hpp"

namespace agent_framework {
namespace command {
namespace storage {
namespace json {

using namespace agent_framework::command;
using agent_framework::command::CommandJson;

/*! JSON storage command class */
class AddLogicalDrive : public CommandJson {
public:
    /*! Agent tag string */
    static constexpr const char* AGENT = storage::AddLogicalDrive::AGENT;

    /*! Command name tag string */
    static constexpr const char* TAG = storage::AddLogicalDrive::TAG;

    /*!
     * @brief Create JSON command
     * */
    AddLogicalDrive();

    /*!
     * @brief JSON RPC method
     *
     * @param[in] params JSON RPC params request
     * @param[out] result JSON RPC result response
     * */
    void method(const Json::Value& params, Json::Value& result) final override;

    /*!
     * @brief JSON RPC notification
     *
     * @param[in] params JSON RPC params request
     * */
    void notification(const Json::Value& params) final override;
};

} /* namespace json */
} /* namespace storage */
} /* namespace command */
} /* namespace agent_framework */

#endif /* AGENT_FRAMEWORK_COMMAND_JSON_STORAGE_ADD_LOGICAL_DRIVE_HPP */
