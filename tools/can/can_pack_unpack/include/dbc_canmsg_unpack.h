/**
* Copyright (C) 2019 Hirain Technologies
* License: Modified BSD Software License Agreement
* Author: Feng DING
* Description:
*/

#ifndef _ITD_IPD_LIBS_TOOLS_CAN_DBC_CANMSG_UNPACK_H_
#define _ITD_IPD_LIBS_TOOLS_CAN_DBC_CANMSG_UNPACK_H_

#include <map>
#include <string>
#include <string.h>
#include "canmsg_define.h"

namespace itd {
namespace tools {
namespace can {

/** the dbc unpack used to transform the can msg to value
* @param in_ [struct Message] the message that you want to unpack
* @param in_ [struct Canmsg] the canmsg
* @param in_ [unsigned int] the size of the value list
* @param out [double array] the array of the values
* @return [int] stat
*/
int unpackCanmsg (const Message &m, const Canmsg &msg, const size_t valueSize, double *value);

/**
* pack one Signal
* @param in_ [struct Signal] the Signal that you want to unpack
* @param in_ [unsigned char array] the data array of the can msg
* @return [double] the value that you unpack from the Signal
*/
real64_T unpackSignal (const Signal &s, const uint8_T *data);

}  // namespace can
}  // namespace tools
}  // namespace itd

#endif  //_ITD_IPD_LIBS_TOOLS_CAN_DBC_CANMSG_UNPACK_H_
