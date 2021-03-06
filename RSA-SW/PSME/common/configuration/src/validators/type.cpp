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
 * @file type.cpp
 *
 * @brief TypeValidator implementation
 * */

#include "configuration/validators/type.hpp"
#include "json/json.hpp"

using namespace configuration;

bool TypeValidator::is_valid(const json::Value& value) {
    if ("string" == m_type) {
        return value.is_string();
    }

    if ("int" == m_type) {
        return value.is_int();
    }

    if ("uint" == m_type) {
        return value.is_uint();
    }

    if ("bool" == m_type) {
        return value.is_boolean();
    }

    if ("array" == m_type) {
        return value.is_array();
    }

    if ("null" == m_type) {
        return value.is_null();
    }

    if ("object" == m_type) {
        return value.is_object();
    }
    return false;
}

std::string TypeValidator::get_error() const {
    return "is not valid type " + m_type;
}
