#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "subscriber.h"
#include "handler.h"
#include "msg.pb.h"

#define HOST "192.168.8.202"
#define PORT 1883

void OnMessage(const itd::communication::protobuf::PointCloud &cloud) {
  printf("%d\n", cloud.width());
}

void OnLog(int level, const char *str) {
  printf("Client log. %d %s\n", level, str);
}

int main() {
  itd::communication::Handler hander(HOST, PORT);
  itd::communication::Subscriber sub = hander.subscribe<itd::communication::protobuf::PointCloud>("Test", OnMessage);
  // if need username and password for mqtt server
  // itd::communication::Handler hander(KEEP_ALIVE, HOST, PORT, USERNAME, PASSWORD);
  // if need a callback of log after subscribe
  // itd::communication::Subscriber pub = hander.subscribe<itd::communication::protobuf::PointCloud>("Test", OnMessage, OnLog);
  sub.Spin();
  return 0;
}
