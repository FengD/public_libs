/**
* Copyright (C) 2019 Hirain Technologies
* License: Modified BSD Software License Agreement
* Author: Feng DING
* Description:
*/

#ifndef _ITD_IPD_LIBS_TOOLS_CAN_DBC_CANMSG_PACK_H_
#define _ITD_IPD_LIBS_TOOLS_CAN_DBC_CANMSG_PACK_H_

#include <map>
#include <string>
#include <string.h>
#include "canmsg_define.h"

namespace itd {
namespace tools {
namespace can {

/** the dbc pack used to transform the value to can msg
* @param in_ [struct Message] the message that you want to pack
* @param in_ [unsigned int] the size of the value list
* @param in_ [float array] the array of the values
* @param out [struct Canmsg] the canmsg
* @return [int] stat pack
*/
int packCanmsg (const Message &m, const size_t &valueSize, const double *value, Canmsg *msg);

/**
* pack one Signal
* @param in_ [struct Signal] the Signal that you want to pack
* @param in_ [double] the value that you want to pack in_ the Signal
* @param out [unsigned char array] the data array of the can msg
*/
void packSignal (const Signal &s, const double &value, uint8_T *data);

}  // namespace can
}  // namespace tools
}  // namespace itd

#endif  //_ITD_IPD_LIBS_TOOLS_CAN_DBC_CANMSG_PACK_H_
