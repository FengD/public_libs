// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef COMMUNICATION_TCP_INCLUDE_TCP_CLIENT_H_
#define COMMUNICATION_TCP_INCLUDE_TCP_CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdint.h>
#include <vector>
#include <iostream>
#include <string>

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

#endif  // COMMUNICATION_TCP_INCLUDE_TCP_CLIENT_H_
