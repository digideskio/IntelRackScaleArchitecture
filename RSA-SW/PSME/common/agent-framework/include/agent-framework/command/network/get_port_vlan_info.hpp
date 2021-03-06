/*!
 * Copyright (c) 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file command/network/get_port_vlan_info.hpp
 * @brief Generic network GetPortVlanInfo command
 * */

#ifndef AGENT_FRAMEWORK_COMMAND_NETWORK_GET_PORT_VLAN_INFO_HPP
#define AGENT_FRAMEWORK_COMMAND_NETWORK_GET_PORT_VLAN_INFO_HPP

#include "agent-framework/command/command.hpp"
#include "agent-framework/module/status.hpp"
#include "agent-framework/module/oem_data.hpp"
#include "agent-framework/module/ipv4_address.hpp"
#include "agent-framework/module/ipv6_address.hpp"

#include <string>

namespace agent_framework {
namespace command {
namespace network {

/* Forward declaration */
namespace json { class GetPortVlanInfo; }

using IPv4Address = agent_framework::generic::IPv4Address;
using IPv6Address = agent_framework::generic::IPv6Address;

/*! Generic network command GetPortVlanInfo */
class GetPortVlanInfo : public Command {
public:
    class Request;
    class Response;

    /*! Tag string for identify agent */
    static constexpr const char AGENT[] = "Network";

    /*! Tag string for identify command */
    static constexpr const char TAG[] = "getPortVlanInfo";

    /*!
     * @brief Execute command with given request and response argument
     *
     * @param[in]   request     Input request argument
     * @param[out]  response    Output response argument
     * */
    virtual void execute(const Request& request, Response& response) = 0;

    /*! Command destructor */
    virtual ~GetPortVlanInfo();
protected:
    /*!
     * @brief Execute command with givent command arguments
     *
     * @param[in]   in      Input command argument
     * @param[out]  out     Output command argument
     * */
    void execute(const Argument& in, Argument& out) override final {
        execute(static_cast<const Request&>(in), static_cast<Response&>(out));
    }
public:
    /*! Argument request to execute */
    class Request : public Argument {
    private:
        friend class json::GetPortVlanInfo;
        std::string m_component{};
        string m_port_identifier{};
        string m_vlan_identifier{};
    public:
        /*!
         * @brief Get component from request
         * @return uuid string
         * */
        const string& get_component() const {
            return m_component;
        }

        /*!
         * @brief Get port identifier
         * @return Port identifier
         * */
        const string& get_port_identifier() const {
            return m_port_identifier;
        }

        /*!
         * @brief Get vlan identifier
         * @return Vlan identifier
         * */
        const string& get_vlan_identifier() const {
            return m_vlan_identifier;
        }

        ~Request();
    };

    /*! Argument response from execute */
    class Response : public Argument {
    private:
        using Status = agent_framework::generic::Status;
        using OEMData = agent_framework::generic::OEMData;

        friend class json::GetPortVlanInfo;
        Status m_status{};
        unsigned int m_vlan_id{};
        bool m_vlan_enable{};
        bool m_tagged{};
        IPv4Address m_ipv4address{};
        IPv6Address m_ipv6address{};
        OEMData m_oem_data{};
    public:
        /*!
         * @brief Switch port status
         * @param[in] status Port status
         * */
        void set_status(const Status& status) {
            m_status = status;
        }

        /*!
         * @brief Set vlan id
         * @param vlan_id vlan id
         */
        void set_vlan_id(const unsigned int vlan_id) {
            m_vlan_id = vlan_id;
        }

        /*!
         * @brief Set vlan enable
         * @param vlan_enable vlan enable
         */
        void set_vlan_enable(const bool vlan_enable) {
            m_vlan_enable = vlan_enable;
        }

        /*!
         * @brief Set tagged
         * @param tagged tagged
         */
        void set_tagged(const bool tagged) {
            m_tagged = tagged;
        }

        /*!
         * @brief Set IPv4 address
         * @param ipv4address IPv4 address
         */
        void set_ipv4address(const IPv4Address& ipv4address) {
            m_ipv4address  = ipv4address;
        }

        /*!
         * @brief Set IPv6 address
         * @param ipv6address IPv6 address
         */
        void set_ipv6address(const IPv6Address& ipv6address) {
            m_ipv6address = ipv6address;
        }


        /*!
         * @brief Set oem data
         * @param oem_data oem data
         */
        void set_oem(const OEMData& oem_data) {
            m_oem_data = oem_data;
        }

        ~Response();
    };
};

}
}
}

#endif /* AGENT_FRAMEWORK_COMMAND_NETWORK_GET_PORT_VLAN_INFO_HPP */
