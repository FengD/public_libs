/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */

#ifndef _ITD_IPD_LIBS_COMMUNICATION_SOCKET_CAN_HANDLER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_SOCKET_CAN_HANDLER_H_

#include <stdint.h>

namespace itd {
namespace communication {
class CanHandler {
 public:
  int32_t fd;
  int32_t ifindex;
  bool fd_mode;
};
}  // namespace itd
}  // namespace communication


#endif  //_ITD_IPD_LIBS_COMMUNICATION_SOCKET_CAN_HANDLER_H_
