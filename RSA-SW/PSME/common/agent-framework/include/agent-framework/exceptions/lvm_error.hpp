/*!
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
 *
 * @file lvm_error.hpp
 *
 * @brief Lvm error interface
 * */

#ifndef AGENT_FRAMEWORK_EXCEPTIONS_LVM_ERROR_HPP
#define AGENT_FRAMEWORK_EXCEPTIONS_LVM_ERROR_HPP

#include "agent-framework/exceptions/exception_base.hpp"

namespace agent_framework {
namespace exceptions {

/*! Not found exception class */
class LvmError final : public ExceptionBase {
public:
    explicit LvmError(const std::string& msg) :
                ExceptionBase{ErrorCode::LVM, msg} {}

    ~LvmError();
};

} // namesapce exceptions
} // namespace agent_framework

#endif	/* AGENT_FRAMEWORK_EXCEPTIONS_LVM_ERROR_HPP */
