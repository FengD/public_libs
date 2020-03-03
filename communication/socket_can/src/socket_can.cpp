/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */


#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <stdbool.h>
#include "socket_can.h"
#include "socket_can_config.h"
#include "socket_can_handler.h"
#include "hlog.h"
#include "error_code.h"

namespace itd {
namespace communication {

int32_t SocketCan::can_socket_cfg(struct CanHandler *hdl, struct CanConfig *cfg) {
  signal(SIGPIPE, SIG_IGN);
  struct sockaddr_can addr;
  struct ifreq ifr;

  hdl->fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
  if (hdl->fd < 0) {
    LOGERROR("%s Error while opening socket. errno: %d\n", __func__, errno);
    return ERR_IO;
  }

  addr.can_family  = AF_CAN;
  strcpy(ifr.ifr_name, cfg->ifname);

  if (ioctl(hdl->fd, SIOCGIFINDEX, &ifr)) {
    LOGERROR("%s Error getting interface index. errno: %d\n",  __func__, errno);
    return ERR_INTERFACE;
  }
  addr.can_ifindex = ifr.ifr_ifindex;

  if (bind(hdl->fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    LOGERROR("%s Error in socket bind. errno: %d\n",  __func__, errno);
    return ERR_BIND;
  }

   // whether receive own message 1 yes(default) 0 no
  if (cfg->loopback >= 0 && cfg->loopback <= 1) {
    setsockopt(hdl->fd, SOL_CAN_RAW, CAN_RAW_LOOPBACK, &cfg->loopback, sizeof(cfg->loopback));
  }

  if (cfg->is_filter_set){
    if (cfg->rx_filter) {
      setsockopt(hdl->fd, SOL_CAN_RAW, CAN_RAW_FILTER, cfg->rx_filter, cfg->rx_filter_len * sizeof(can_filter));
    }
  } else {
     // if no need to receive, the line behind could save the space of receive queue in the kernal
    setsockopt(hdl->fd, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
  }

  can_err_mask_t err_mask = ( CAN_ERR_TRX | CAN_ERR_TX_TIMEOUT | CAN_ERR_CRTL | CAN_ERR_BUSOFF );
  setsockopt(hdl->fd, SOL_CAN_RAW, CAN_RAW_ERR_FILTER, &err_mask, sizeof(err_mask));

  return NO_ERROR;
}

int32_t SocketCan::can_open(struct CanHandler **hdl, struct CanConfig *cfg) {
  *hdl = (struct CanHandler *) malloc(sizeof(struct CanHandler));
  if (!*hdl) {
    return ERR_IO;
  }

  memset(*hdl, 0, sizeof(struct CanHandler));

  if (can_socket_cfg(*hdl, cfg) != 0) {
    LOGERROR("%s Error in socket open. errno: %d\n",  __func__, errno);
    free(*hdl);
    *hdl = NULL;
    return ERR_CAN_OPEN;
  }

  return NO_ERROR;
}

int32_t SocketCan::can_close(struct CanHandler **hdl) {
  if (!hdl || !(*hdl)) {
    LOGERROR("%s Error in socket close. errno: %d\n",  __func__, errno);
    return ERR_IO;
  }

  if (close((*hdl)->fd) < 0) {
    LOGERROR("%s Error in socket close. errno: %d\n",  __func__, errno);
    return ERR_CAN_CLOSE;
  }

  free(*hdl);
  *hdl = NULL;

  return NO_ERROR;
}

int32_t SocketCan::can_read(struct CanHandler *hdl, struct can_frame *frame) {
  ssize_t nbytes = -1;
  nbytes = read(hdl->fd, frame, sizeof(struct can_frame));
  if (nbytes == -1) {
    LOGERROR("%s Error in read if nbytes == -1. errno: %d\n",  __func__, errno);
    return ERR_CAN_READ;
  } else if (nbytes == 0) {
    LOGERROR("%s Error in read if nbytes == 0. errno: %d\n",  __func__, errno);
    return ERR_CAN_READ;
  }
  return NO_ERROR;
}

int32_t SocketCan::can_write(struct CanHandler *hdl, const struct can_frame *frame) {
  ssize_t nbytes = -1;
  nbytes = write(hdl->fd, frame, sizeof(can_frame));
  if (nbytes == -1) {
    LOGERROR("%s Error in write nbytes == -1. errno: %d\n",  __func__, errno);
    return ERR_CAN_WRITE;
  }
  usleep(100);
  return NO_ERROR;
}

}  // namespace itd
}  // namespace communication
