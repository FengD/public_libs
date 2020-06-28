// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: socket can

#ifndef COMMUNICATION_SOCKET_CAN_INCLUDE_SOCKET_CAN_CONFIG_H_
#define COMMUNICATION_SOCKET_CAN_INCLUDE_SOCKET_CAN_CONFIG_H_

#include <stdint.h>
#include <sys/types.h>

namespace itd {
namespace communication {

class CanConfig {
 public:
  char *ifname;
  int32_t loopback;
  size_t mtu;
  int32_t is_filter_set;
  struct can_filter *rx_filter;
  size_t rx_filter_len;
};

}  // namespace communication
}  // namespace itd


#endif  // COMMUNICATION_SOCKET_CAN_INCLUDE_SOCKET_CAN_CONFIG_H_
