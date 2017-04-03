/* ****************************************************************
 *
 * Copyright 2015 Samsung Electronics All Rights Reserved.
 *
 *
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
 ******************************************************************/

/**
 * @file
 * This file contains the APIs for routing manager.
 */
#ifndef ROUTING_MANAGER_H_
#define ROUTING_MANAGER_H_

#include "octypes.h"
#include "ocserverrequest.h"
#include "ocresource.h"
#include "routingutility.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Initialize the Routing Manager.
 * @return  ::OC_STACK_OK or Appropriate error code.
 */
// TODO: Future addition pertaining to security, RM should be given ACL callback from RI.
OCStackResult RMInitialize();

/**
 * Terminates the Routing Manager.
 * @return  ::OC_STACK_OK or Appropriate error code.
 */
OCStackResult RMTerminate();

/**
 * This API will be called from RI layer whenever there is a request for the GATEWAY
 * Virtual Resource.
 * @param[in,out]   request    Request Received.
 * @param[in]       resource   Resource handle used for sending the response.
 * @return  ::OC_STACK_OK or Appropriate error code.
 */
OCStackResult RMHandleGatewayRequest(OCServerRequest *request, const OCResource *resource);

/**
 * API to handle the Response payload.  The Gateway entries are parsed from
 * the payload using routingmessageparser apis, addition or removal of
 * Gateway entries is performed.
 * @param[in]   devAddr    Address of the Device that sent the payload.
 * @param[in]   payload    Response payload.
 * @return  ::OC_STACK_OK or Appropriate error code.
 */
OCStackResult RMHandleResponsePayload(const OCDevAddr *devAddr, const OCRepPayload *payload);

/**
 * Process the routing manager timer to send notification to all the observers.
 */
void RMProcess();

/**
 * API to form the payload with gateway ID.
 * @param[out]   payload    Payload generated by routing message parser.
 * @return  ::OC_STACK_OK or Appropriate error code.
 */
OCStackResult RMGetGatewayPayload(OCRepPayload **payload);

/**
 * API to get the gateway UUID of its own.
 * @return  Gateway UUID.
 */
uint32_t RMGetGatewayId();

/**
 * API to get the multicast sequence number.
 * @return  Multicast sequence number.
 */
uint16_t RMGetMcastSeqNumber();

/**
 * On reception of request from CA, RI sends to this function.
 * This checks if the route option is present and adds routing information to
 * to the route option data.
 * @param[in,out]  message           Received coap packet.
 * @param[in]      sender            RemoteEndpoint which sent the packet.
 * @param[out]     selfDestination   Populated by RM by parsing message, CA then forwards packet to
 *                                   "destination".
 * @param[out]     isEmptyMsg        Populated by RM by parsing the RouteOption.  If the MSGType is ACK
 *                                   in route option and is for self, then this flag is set.
 * @return  ::CA_STATUS_OK or Appropriate error code.
 */
OCStackResult RMHandleRequest(CARequestInfo_t *message, const CAEndpoint_t *sender,
                              bool *selfDestination, bool *isEmptyMsg);

/**
 * On reception of response from CA, RI sends to this function.
 * This checks if the route option is present and adds routing information to
 * to the route option data.
 * @param[in,out]  message           Received coap packet.
 * @param[in]      sender            RemoteEndpoint which sent the packet.
 * @param[out]     selfDestination   Populated by RM by parsing message to know if response is
 *                                   for its own.
 * @return  ::CA_STATUS_OK or Appropriate error code.
 */
OCStackResult RMHandleResponse(CAResponseInfo_t *message, const CAEndpoint_t *sender,
                               bool *selfDestination);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ROUTING_MANAGER_H_ */
