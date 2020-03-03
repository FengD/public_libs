/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */

#ifndef _MODULE_COMMUNICATION_SOCKET_CAN_CONFIG_H_
#define _MODULE_COMMUNICATION_SOCKET_CAN_CONFIG_H_

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

}  // namespace itd
}  // namespace communication


#endif  //_MODULE_COMMUNICATION_SOCKET_CAN_CONFIG_H_
