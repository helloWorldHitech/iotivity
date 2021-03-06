//******************************************************************
//
// Copyright 2014 Intel Mobile Communications GmbH All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//******************************************************************


/**
 * @file
 *
 * This file contains all the variables which can be configured/modified as
 * per platform or specific product usage scenarios.
 */

#ifndef OCSTACK_CONFIG_H_
#define OCSTACK_CONFIG_H_

/**
 * Maximum length of the URI supported by client/server while processing
 * REST requests/responses.
 */
#ifdef ARDUINO
#define MAX_URI_LENGTH (64)
#else
#define MAX_URI_LENGTH (256)
#endif

/**
 * Maximum length of the query supported by client/server while processing
 * REST requests/responses.
 */
#ifdef ARDUINO
#define MAX_QUERY_LENGTH (64)
#else
#define MAX_QUERY_LENGTH (256)
#endif


/**
 * Maximum length of the Manufacturer name supported by the server
 * for manufacturer name.
 * @deprecated use MAX_PLATFORM_NAME_LENGTH instead.
 */
#define MAX_MANUFACTURER_NAME_LENGTH (64)

/**
 * Maximum length of the URL to the Manufacturer details supported by
 * the server.
 * @deprecated use MAX_PLATFORM_URL_LENGTH instead.
 */
#define MAX_MANUFACTURER_URL_LENGTH (256)

/**
 * Maximum length of the value supported by the server
 * for platform property of type string.
 */
#define MAX_PLATFORM_NAME_LENGTH (64)

/**
 * Maximum length of the URL supported by the server
 * for platform property of type url.
 */
#define MAX_PLATFORM_URL_LENGTH (256)

/**
 * Maximum number of resources which can be contained inside collection
 * resource.
 */
#define MAX_CONTAINED_RESOURCES  (5)

/**
 *  Maximum number of vendor specific header options an application can set or receive
 *  in PDU
 */
#ifdef ARDUINO
#define MAX_HEADER_OPTIONS (2)
#else
#define MAX_HEADER_OPTIONS (50)
#endif

/**
 *  Maximum Length of the vendor specific header option
 */
#ifdef ARDUINO
#define MAX_HEADER_OPTION_DATA_LENGTH (20)
#else
#define MAX_HEADER_OPTION_DATA_LENGTH (1024)
#endif

/**
 * Sets the time to live (TTL) for response callback(s).
 * The callback(s) will be up for deletion after such time but are not guaranteed
 * to be deleted immediately and you may get responses even after timeout.
 * This timeout will NOT apply to OBSERVE requests. OBSERVE needs an explicit cancel using OCCancel().
 * @note: Changing the setting to a very long duration may lead to unsupported and untested
 * operation. Setting this to as small a value as reasonable will reclaim memory faster.
 */
#define MAX_CB_TIMEOUT_SECONDS   (60 * 2)

#endif //OCSTACK_CONFIG_H_
