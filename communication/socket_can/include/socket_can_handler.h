// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: socket can

#ifndef COMMUNICATION_SOCKET_CAN_INCLUDE_HANDLER_H_
#define COMMUNICATION_SOCKET_CAN_INCLUDE_HANDLER_H_

#include <stdint.h>

namespace itd {
namespace communication {
class CanHandler {
 public:
  int32_t fd;
  int32_t ifindex;
  bool fd_mode;
};
}  // namespace communication
}  // namespace itd


#endif  // COMMUNICATION_SOCKET_CAN_INCLUDE_HANDLER_H_
