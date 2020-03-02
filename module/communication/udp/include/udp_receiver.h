// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the udp input

#ifndef _MODULE_COMMUNICATION_UDP_RECEIVER_H_
#define _MODULE_COMMUNICATION_UDP_RECEIVER_H_

#include <unistd.h>
#include <string>
#include <netinet/in.h>

namespace itd {
namespace communication {

class UdpReceiver {
 public:
  UdpReceiver();
  ~UdpReceiver();
  int32_t Setup(const std::string source_ip, const int32_t port, const std::string multicast_ip = "");
  int32_t GetPacket(const int32_t& packet_size, uint8_t *pkt);
  void set_source_ip_str(const std::string& source_ip_str);
  void set_multicast_ip_str(const std::string& multicast_ip_str);
  void set_port(const int32_t& port);
 private:
  std::string source_ip_str_;
  std::string multicast_ip_str_;
  int32_t port_;
  int32_t sockfd_;
  in_addr source_ip_;
  static const int32_t POLL_TIMEOUT = 1000;
};

}  // namespace communication
}  // namespace itd

#endif  // _MODULE_COMMUNICATION_UDP_RECEIVER_H_
