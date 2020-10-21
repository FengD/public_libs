// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: example mqtt sub

#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "subscriber.h"
#include "handler.h"
#include "itd_ipd_std_msgs.pb.h"

#define HOST "dingfeng.website"
#define PORT 1883
#define USERNAME "hirain"
#define PASSWORD "123"

void OnMessage(const itd::communication::protobuf::Int32 &data) {
  printf("%d\n", data.data());
}

void OnLog(int level, const char *str) {
  printf("Client log. %d %s\n", level, str);
}

int main() {
  itd::communication::Handler handler(HOST, PORT, USERNAME, PASSWORD);
  // itd::communication::Handler handler(HOST, PORT);
  itd::communication::Subscriber *sub = handler.subscribe<itd::communication::protobuf::Int32>("Test", OnMessage, 2);
  // if need username and password for mqtt server
  // itd::communication::Handler handler(KEEP_ALIVE, HOST, PORT, USERNAME, PASSWORD);
  // if need a callback of log after subscribe
  // itd::communication::Subscriber sub = handler.subscribe<itd::communication::protobuf::PointCloud>("Test",
  //                                                                                                  OnMessage,
  //                                                                                                  OnLog);
  sub->Spin();
  delete sub;
  return 0;
}
