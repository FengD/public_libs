// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: udp sender

#ifndef _ITD_IPD_LIBS_COMMUNICATION_UDP_SENDER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_UDP_SENDER_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <string>
#include <stdint.h>

namespace itd {
namespace communication {

class UdpSender {
 public:
  UdpSender();
  ~UdpSender();
  int32_t Send(const void *msg, const int32_t& len);
  int32_t Setup(const std::string &ip, const int32_t &port);

 private:
  std::string target_ip_;
  int32_t port_;
  int32_t socket_, ret_;
  struct sockaddr_in client_address_, remote_server_address_;
  struct hostent *host_;
  int32_t broadcast_;
  int32_t Init();
};

}  // namespace communication
}  // namespace itd

#endif  // _ITD_IPD_LIBS_COMMUNICATION_UDP_SENDER_H_
