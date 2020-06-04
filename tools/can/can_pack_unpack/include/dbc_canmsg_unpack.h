// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: Can msg uppack
// Date: 2019-11-22
// Change Log:

#ifndef TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_DBC_CANMSG_UNPACK_H_
#define TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_DBC_CANMSG_UNPACK_H_

#include <string.h>
#include <map>
#include <string>
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
int unpackCanmsg(const Message &m, const Canmsg &msg, const size_t valueSize, double *value);

/**
* pack one Signal
* @param in_ [struct Signal] the Signal that you want to unpack
* @param in_ [unsigned char array] the data array of the can msg
* @return [double] the value that you unpack from the Signal
*/
double unpackSignal(const Signal &s, const uint8_t *data);

}  // namespace can
}  // namespace tools
}  // namespace itd

#endif  // TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_DBC_CANMSG_UNPACK_H_
