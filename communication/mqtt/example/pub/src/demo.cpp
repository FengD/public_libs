// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: example mqtt pub


#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "publisher.h"
#include "handler.h"
#include "itd_ipd_std_msgs.pb.h"

#define HOST "dingfeng.website"
#define PORT 1883
#define USERNAME "hirain"
#define PASSWORD "123"

void OnLog(int level, const char *str) {
  printf("Client log. %d %s\n", level, str);
}

int main() {
  // itd::communication::Handler handler(HOST, PORT);
  // itd::communication::Publisher pub = handler.advertise<itd::communication::protobuf::PointCloud>("Test");
  // if need username and password for mqtt server
  itd::communication::Handler handler(HOST, PORT, USERNAME, PASSWORD);
  // if need a callback of log after publish
  itd::communication::Publisher *pub = handler.advertise<itd::communication::protobuf::Int32>("Test", OnLog);
  int i = 0;
  while (1) {
    itd::communication::protobuf::Int32 msg;
    // msg.set_height(10);
    // msg.set_width(i++);
    msg.set_data(i++);
    pub->Publish(msg, 2);
    usleep(1000000);
  }
  delete pub;
  return 0;
}
