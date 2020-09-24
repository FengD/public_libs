// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the udp input

#include "udp_sender.h"

int main(int argc, char **argv) {
  itd::communication::UdpSender *udp_sender = new itd::communication::UdpSender();
  udp_sender->Setup("localhost", 9111);
  float x = 1.1;
  udp_sender->Send(&x, sizeof(x));
  return 0;
}
