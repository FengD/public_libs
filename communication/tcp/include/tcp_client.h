// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef _MODULE_COMMUNICATION_TCP_CLIENT_H_
#define _MODULE_COMMUNICATION_TCP_CLIENT_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netdb.h>
#include <vector>
#include <stdint.h>

namespace itd {
namespace communication {

class TcpClient {
 private:
  int32_t socket_;
  std::string ip_str_;
  int32_t port_;
  struct sockaddr_in ip_;

 public:
  TcpClient();
  int32_t Setup(const std::string &ip_str, const int32_t &port);
  int32_t Send(const uint8_t *data, const int32_t &data_len);
  int32_t Receive(const int32_t &data_len, uint8_t *data);
  void Exit();
};

}  // namespace communication
}  // namespace itd

#endif  // _MODULE_COMMUNICATION_TCP_CLIENT_H_
