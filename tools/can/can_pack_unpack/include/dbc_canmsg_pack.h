// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: Can msg pack
// Date: 2019-11-22
// Change Log:

#ifndef TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_CANMSG_PACK_H_
#define TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_CANMSG_PACK_H_

#include <string.h>
#include <map>
#include <string>
#include "canmsg_define.h"

namespace itd {
namespace tools {
namespace can {

/** the dbc pack used to transform the value to can msg
* @param in_ [struct Message] the message that you want to pack
* @param in_ [unsigned int] the size of the value list
* @param in_ [double array] the array of the values
* @param out [struct Canmsg] the canmsg
* @return [int] stat pack
*/
int packCanmsg(const Message &m, const size_t &valueSize, const double *value, Canmsg *msg);

/**
* pack one Signal
* @param in_ [struct Signal] the Signal that you want to pack
* @param in_ [double] the value that you want to pack in_ the Signal
* @param out [unsigned char array] the data array of the can msg
*/
void packSignal(const Signal &s, const double &value, uint8_t *data);

}  // namespace can
}  // namespace tools
}  // namespace itd

#endif  // TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_CANMSG_PACK_H_
