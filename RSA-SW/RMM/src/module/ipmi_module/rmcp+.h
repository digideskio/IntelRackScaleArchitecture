/**
 * Copyright (c)  2015, Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef _RMCP_PLUS_H_
#define _RMCP_PLUS__H_

#define IPMI20_SUPPORT    0


#if IPMI20_SUPPORT == 1
#define IPMI20_GET_CHANNEL_CIPHER_SUITES	0x54
#define IPMI20_CIPHER_SUITE_START_OF_RECORD_MASK	0xC0
#define IPMI20_CIPHER_STANDARD_CIPHER_SUITE_ID_MASK	0xC0
#define IPMI20_CIPHER_OEM_CIPHER_SUITE_ID_MASK		0xC1
#define IPMI20_CIPHER_SUITE_ALG_TYPE_MASK			0xC0
#define IPMI20_CIPHER_SUITE_ALG_NUMBER_MASK			0x3F
#define IPMI20_CIPHER_SUITE_AUTH_ALG_NUMBER			0x00
#define IPMI20_CIPHER_SUITE_INT_ALG_NUMBER			0x40
#define IPMI20_CIPHER_SUITE_CRYPT_ALG_NUMBER		0x80


#define IPMI20_AUTH_TYPE_OFFSET       0
#define IPMI20_AUTH_TYPE_LEN          1

#define IPMI20_PAYLOAD_TYPE_OFFSET    (IPMI20_AUTH_TYPE_OFFSET + IPMI20_AUTH_TYPE_LEN)
#define IPMI20_PAYLOAD_TYPE_LEN       1

#define IPMI20_PAYLOAD_ENCRYPTED_MASK 0x80
#define IPMI20_PAYLOAD_AUTH_MASK      0x40
#define IPMI20_PAYLOAD_TYPE_MASK      0x3F

#define IPMI20_OEM_IANA_LEN           4
#define IPMI20_OEM_PAYLOAD_ID_LEN     2
#define IPMI20_SESSION_ID_LEN         4
#define IPMI20_SESSION_SEQ_NUM_LEN    4
#define IPMI20_MSG_PAYLOAD_LEN_LEN    2

#define IPMI20_AUTH_TYPE_RMCP_PLUS    0x6

#define IPMI20_SESSION_HEADER_LEN_MIN (IPMI20_AUTH_TYPE_LEN + \
									   IPMI20_PAYLOAD_TYPE_LEN + \
									   IPMI20_SESSION_ID_LEN + \
									   IPMI20_SESSION_SEQ_NUM_LEN + \
									   IPMI20_MSG_PAYLOAD_LEN_LEN)

#define IPMI20_RAKP_SESSION_RANDOM_LEN			16
#define IPMI20_RAKP_BMC_RANDOM_LEN				16
#define IPMI20_RAKP_MAX_USER_NAME_LEN			16
#define IPMI20_RAKP_GUID_LEN					16
#define IPMI20_SESSION_ID_LEN					4
#define IPMI20_BMC_ID_LEN						4
#define IPMI20_PRIVILEGE_LEN					1

/* For IPMI v2.0/RMCP+ open session Request */
#define IPMI20_OPEN_SESS_REQ_MSG_TAG_OFFSET		0
#define IPMI20_OPEN_SESS_REQ_MAX_PRIV_LEVEL_OFFSET	(IPMI20_OPEN_SESS_REQ_MSG_TAG_OFFSET + 1)
#define IPMI20_OPEN_SESS_REQ_SESSION_ID_OFFSET	(IPMI20_OPEN_SESS_REQ_MAX_PRIV_LEVEL_OFFSET + 3)
#define IPMI20_OPEN_SESS_REQ_SESSION_ID_LEN		4
#define IPMI20_OPEN_SESS_REQ_AUTH_ALG_OFFSET	(IPMI20_OPEN_SESS_REQ_SESSION_ID_OFFSET \
												 + IPMI20_OPEN_SESS_REQ_SESSION_ID_LEN)
#define IPMI20_OPEN_SESS_REQ_AUTH_ALG_LEN		8
#define IPMI20_OPEN_SESS_REQ_INT_ALG_OFFSET		(IPMI20_OPEN_SESS_REQ_AUTH_ALG_OFFSET \
												 + IPMI20_OPEN_SESS_REQ_AUTH_ALG_LEN)
#define IPMI20_OPEN_SESS_REQ_INT_ALG_LEN		8
#define IPMI20_OPEN_SESS_REQ_CRYPT_ALG_OFFSET	(IPMI20_OPEN_SESS_REQ_INT_ALG_OFFSET \
												 + IPMI20_OPEN_SESS_REQ_INT_ALG_LEN)
#define IPMI20_OPEN_SESS_REQ_CRYPT_ALG_LEN		8

#define IPMI20_OPEN_SESS_REQ_SIZE				32

/* For IPMI v2.0/RMCP+ open session Response */
#define IPMI20_OPEN_SESS_RSP_MSG_TAG_OFFSET		0
#define IPMI20_OPEN_SESS_RSP_STAT_CODE_OFFSET	(IPMI20_OPEN_SESS_RSP_MSG_TAG_OFFSET + 1)
#define IPMI20_OPEN_SESS_RSP_MAX_PRIV_LEVEL_OFFSET	(IPMI20_OPEN_SESS_RSP_STAT_CODE_OFFSET + 1)
#define IPMI20_OPEN_SESS_RSP_SESSION_ID_OFFSET	(IPMI20_OPEN_SESS_RSP_MAX_PRIV_LEVEL_OFFSET + 2)
#define IPMI20_OPEN_SESS_RSP_SESSION_ID_LEN		4
#define IPMI20_OPEN_SESS_RSP_BMC_ID_OFFSET		(IPMI20_OPEN_SESS_RSP_SESSION_ID_OFFSET \
												 + IPMI20_OPEN_SESS_RSP_SESSION_ID_LEN)
#define IPMI20_OPEN_SESS_RSP_BMC_ID_LEN			4
#define IPMI20_OPEN_SESS_RSP_AUTH_ALG_OFFSET	(IPMI20_OPEN_SESS_RSP_BMC_ID_OFFSET \
												 + IPMI20_OPEN_SESS_RSP_BMC_ID_LEN)
#define IPMI20_OPEN_SESS_RSP_AUTH_ALG_LEN		8
#define IPMI20_OPEN_SESS_RSP_INT_ALG_OFFSET		(IPMI20_OPEN_SESS_RSP_AUTH_ALG_OFFSET \
												 + IPMI20_OPEN_SESS_RSP_AUTH_ALG_LEN)
#define IPMI20_OPEN_SESS_RSP_INT_ALG_LEN		8
#define IPMI20_OPEN_SESS_RSP_CRYPT_ALG_OFFSET	(IPMI20_OPEN_SESS_RSP_INT_ALG_OFFSET \
												 + IPMI20_OPEN_SESS_RSP_INT_ALG_LEN)
#define IPMI20_OPEN_SESS_RSP_CRYPT_ALG_LEN		8

/* For IPMI v2.0/RMCP+ RAKP Message 1 */
#define IPMI20_RAKP_MSG_1_MSG_TAG_OFFSET		0
#define IPMI20_RAKP_MSG_1_BMC_ID_OFFSET			(IPMI20_RAKP_MSG_1_MSG_TAG_OFFSET + 4)
#define IPMI20_RAKP_MSG_1_BMC_ID_LEN			4
#define IPMI20_RAKP_MSG_1_SESSION_RANDOM_OFFSET	(IPMI20_RAKP_MSG_1_MSG_TAG_OFFSET \
												 + IPMI20_RAKP_MSG_1_BMC_ID_LEN)
#define IPMI20_RAKP_MSG_1_SESSION_RANDOM_LEN	16
#define IPMI20_RAKP_MSG_1_MAX_PRIV_LEVEL_OFFSET	(IPMI20_RAKP_MSG_1_SESSION_RANDOM_OFFSET \
												 + IPMI20_RAKP_MSG_1_SESSION_RANDOM_LEN)
#define IPMI20_RAKP_MSG_1_USER_NAME_LEN_OFFSET	(IPMI20_RAKP_MSG_1_MAX_PRIV_LEVEL_OFFSET + 3)
#define IPMI20_RAKP_MSG_1_USER_NAME_OFFSET		(IPMI20_RAKP_MSG_1_USER_NAME_LEN_OFFSET + 1)
#define IPMI20_RAKP_MSG_1_USER_NAME_LEN			16

									#define IPMI20_RAKP_MSG_1_SIZE					44

/* For IPMI v2.0/RMCP+ RAKP Message 2 */
#define IPMI20_RAKP_MSG_2_MSG_TAG_OFFSET		0
#define IPMI20_RAKP_MSG_2_STAT_CODE_OFFSET		(IPMI20_RAKP_MSG_2_MSG_TAG_OFFSET + 1)
#define IPMI20_RAKP_MSG_2_SESSION_ID_OFFSET		(IPMI20_RAKP_MSG_2_STAT_CODE_OFFSET + 3)
#define IPMI20_RAKP_MSG_2_SESSION_ID_LEN		4
#define IPMI20_RAKP_MSG_2_BMC_RANDOM_NUM_OFFSET	(IPMI20_RAKP_MSG_2_SESSION_ID_OFFSET \
												 + IPMI20_RAKP_MSG_2_SESSION_ID_LEN)
#define IPMI20_RAKP_MSG_2_BMC_RANDOM_NUM_LEN	16
#define IPMI20_RAKP_MSG_2_BMC_GUID_OFFSET		(IPMI20_RAKP_MSG_2_BMC_RANDOM_NUM_OFFSET \
												 + IPMI20_RAKP_MSG_2_BMC_RANDOM_NUM_LEN)
#define IPMI20_RAKP_MSG_2_BMC_GUID_LEN			16
#define IPMI20_RAKP_MSG_2_AUTH_CODE_OFFSET		(IPMI20_RAKP_MSG_2_BMC_GUID_OFFSET \
												 + IPMI20_RAKP_MSG_2_BMC_GUID_LEN)
#define IPMI20_RAKP_MSG_2_AUTH_CODE_MAX_LEN		20

/* For IPMI v2.0/RMCP+ RAKP Message 3 */
#define IPMI20_RAKP_MSG_3_MSG_TAG_OFFSET		0
#define IPMI20_RAKP_MSG_3_STAT_CODE_OFFSET		(IPMI20_RAKP_MSG_3_MSG_TAG_OFFSET + 1)
#define IPMI20_RAKP_MSG_3_BMC_ID_OFFSET			(IPMI20_RAKP_MSG_3_STAT_CODE_OFFSET + 3)
#define IPMI20_RAKP_MSG_3_BMC_ID_LEN			4
#define IPMI20_RAKP_MSG_3_AUTH_CODE_OFFSET		(IPMI20_RAKP_MSG_3_BMC_ID_OFFSET \
												 + IPMI20_RAKP_MSG_3_BMC_ID_LEN)
#define IPMI20_RAKP_MSG_3_AUTH_CODE_MAX_LEN		20

#define IPMI20_RAKP_MSG_3_MAX_SIZE				28

/* For IPMI v2.0/RMCP+ RAKP Message 4 */
#define IPMI20_RAKP_MSG_4_MSG_TAG_OFFSET		0
#define IPMI20_RAKP_MSG_4_STAT_CODE_OFFSET		(IPMI20_RAKP_MSG_4_MSG_TAG_OFFSET + 1)
#define IPMI20_RAKP_MSG_4_SESSION_ID_OFFSET		(IPMI20_RAKP_MSG_4_STAT_CODE_OFFSET + 3)
#define IPMI20_RAKP_MSG_4_SESSION_ID_LEN		4
#define IPMI20_RAKP_MSG_4_INT_CHECK_OFFSET		(IPMI20_RAKP_MSG_4_SESSION_ID_OFFSET \
												 + IPMI20_RAKP_MSG_4_SESSION_ID_LEN)
#define IPMI20_RAKP_MSG_4_INT_CHECK_MAX_LEN		20

/* For RAKP 2 and RAKP 3, HAMC_SHA1 size is 20 bytes,
   but for RAKP 4 is 12 bytes */
#define RAKP_2_AND_3_HMAC_SHA1_SIZE		20
#define RAKP_4_HMAC_SHA1_SIZE			12

#define RAKP_DATA_CHECK_MAX_LEN	(4 /* Remote console session ID */ \
								 + 4 /* BMC ID */						\
								 + 16 /* Remote console random number */ \
								 + 16 /* BMC random ID */				\
								 + 16 /* BMC GUID */					\
								 + 1 /* Requested Privilege Level(Role) */ \
								 + 1 /* User name length byte */		\
								 + 16 /* Max user name length */)

/* For RAKP 2, 3, 4, HMAC_MD5 size is always 16 bytes (128 bits) */
#define RAKP_HMAC_MD5_SIZE				16

enum rmcp_plus_auth_alg_num {
	AUTH_ALG_RAKP_NONE = 0x00,
	AUTH_ALG_RAKP_HMAC_SHA1,
	AUTH_ALG_RAKP_HMAC_MD5,

	AUTH_ALG_OEM_BEGIN = 0xc0,
	AUTH_ALG_OEM_END = 0xFF,
};

enum rmcp_plus_integrity_alg_num {
	INTEGRITY_ALG_NONE = 0x00,
	INTEGRITY_ALG_HMAC_SHA1_96,
	INTEGRITY_ALG_HMAC_MD5_128,
	INTEGRITY_ALG_MD5_128,

	INTEGRITY_ALG_OEM_BEGIN = 0xc0,
	INTEGRITY_ALG_OEM_END = 0xff,
};

enum rmcp_plus_crypt_alg_num {
	CRYPT_ALG_NONE = 0x00,
	CRYPT_ALG_AES_CBC_128,
	CRYPT_ALG_xRC4_128,
	CRYPT_ALG_xRC4_40,

	CRYPT_ALG_OEM_BEGIN = 0x30,
	CRYPT_ALG_OEM_END = 0x3f,
};

enum rmcp_plus_rakp_msg_stat_codes {
	RMCP_PLUS_STAT_NO_ERR = 0x00,
	RMCP_PLUS_STAT_INSUFFICIENT_RESOUCE_SESS,
	RMCP_PLUS_STAT_INVALID_SESSION_ID,
	RMCP_PLUS_STAT_INVALID_PAYLOAD_TYPE,
	RMCP_PLUS_STAT_INVALID_AUTH_ALGO,
	RMCP_PLUS_STAT_INVALID_INT_ALGO,
	RMCP_PLUS_STAT_NO_MATCH_AUTH_PAYLOAD,
	RMCP_PLUS_STAT_NO_MATCH_INT_PAYLOAD,
	RMCP_PLUS_STAT_INACTIVE_SESSION_ID,
	RMCP_PLUS_STAT_INVALID_ROLE,
	RMCP_PLUS_STAT_UNAUTH_ROLE,
	RMCP_PLUS_STAT_INSUFFICIENT_RESOURCE_REQ_ROLE,
	RMCP_PLUS_STAT_INVALID_NAME_LEN,
	RMCP_PLUS_STAT_UNAUTH_NAME,
	RMCP_PLUS_STAT_UNAUTH_GUID,
	RMCP_PLUS_STAT_INVALID_INT_CHECK_VALUE,
	RMCP_PLUS_STAT_INVALID_CONF_ALGO,
	RMCP_PLUS_STAT_NO_CIPHER_SUITE_MATCH,
	RMCP_PLUS_STAT_ILLEGAL_PARAM,
	RMCP_PLUS_STAT_RESERVED, /* 13h - FFh */
};

enum ipmi20_payload_type_numbers {
	IPMI20_STANDARD_PAYLOAD_IPMI = 0x0,
	IPMI20_STANDARD_PAYLOAD_SOL,
	IPMI20_STANDARD_PAYLOAD_OEM_EXPLICIT,

	IPMI20_SESS_PAYLOAD_OPEN_SESS_REQ = 0x10,
	IPMI20_SESS_PAYLOAD_OPEN_SESS_RSP,
	IPMI20_SESS_PAYLOAD_RAKP_1,
	IPMI20_SESS_PAYLOAD_RAKP_2,
	IPMI20_SESS_PAYLOAD_RAKP_3,
	IPMI20_SESS_PAYLOAD_RAKP_4,

	IPMI20_OEM_PAYLOAD_OEM0 = 0x20,
	IPMI20_OEM_PAYLOAD_OEM1,
	IPMI20_OEM_PAYLOAD_OEM2,
	IPMI20_OEM_PAYLOAD_OEM3,
	IPMI20_OEM_PAYLOAD_OEM4,
	IPMI20_OEM_PAYLOAD_OEM5,
	IPMI20_OEM_PAYLOAD_OEM6,
	IPMI20_OEM_PAYLOAD_OEM7,
};

struct ipmi20_msg {
	unsigned char netfn;
	unsigned char lun;
	unsigned char seq;
	unsigned char cmd;
	unsigned char *data;
	unsigned char data_len;
};

struct rmcp_plus_ipmi_info {
	unsigned int host;
	unsigned int port;

	unsigned char auth_type;
	unsigned char payload_type;
	unsigned int oem_iana;
	unsigned short oem_payload_id;
	unsigned int  session_id;
	unsigned int  session_seq;

	unsigned char seq;
	unsigned char netfn;
	unsigned char cmd;

	int ipmi_data_len;
	unsigned char *ipmi_data;

	int ipmi_trailer_len;
	unsigned char *ipmi_trailer;
};

extern void handle_rmcp_plus_ipmi_msg(struct rmcp_plus_ipmi_info *ipmi_info);
#endif /* End of #if IPMI20_SUPPORT == 1 */

#endif
