/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */

#ifndef _ITD_IPD_LIBS_COMMUNICATION_SOCKET_CAN_
#define _ITD_IPD_LIBS_COMMUNICATION_SOCKET_CAN_

#include <linux/can.h>
#include <linux/can/raw.h>
#include <linux/can/error.h>
#include <sys/types.h>
#include <stdint.h>

namespace itd {
namespace communication {
class CanHandler;
class CanConfig;
class SocketCan {
 private:
  static int32_t can_socket_cfg(struct CanHandler *hdl, struct CanConfig *cfg);

 public:
  static int32_t can_open(struct CanHandler **hdl, struct CanConfig *cfg);
  static int32_t can_close(struct CanHandler **hdl);
  static int32_t can_read(struct CanHandler *hdl, struct can_frame *frame);
  static int32_t can_write(struct CanHandler *hdl, const struct can_frame *frame);
};

}  // namespace itd
}  // namespace communication


#endif  //_ITD_IPD_LIBS_COMMUNICATION_SOCKET_CAN_
