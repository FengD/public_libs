#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "subscriber.h"
#include "handler.h"
#include "itd_ipd_sensor_msgs.pb.h"

#define HOST "192.168.8.224"
#define PORT 1883

void OnMessage(const itd::communication::protobuf::PointCloud &cloud) {
  printf("%d\n", cloud.width());
}

void OnLog(int level, const char *str) {
  printf("Client log. %d %s\n", level, str);
}

int main() {
  itd::communication::Handler handler(HOST, PORT);
  itd::communication::Subscriber *sub = handler.subscribe<itd::communication::protobuf::PointCloud>("Test", OnMessage);
  // if need username and password for mqtt server
  // itd::communication::Handler handler(KEEP_ALIVE, HOST, PORT, USERNAME, PASSWORD);
  // if need a callback of log after subscribe
  // itd::communication::Subscriber sub = handler.subscribe<itd::communication::protobuf::PointCloud>("Test", OnMessage, OnLog);
  sub->Spin();
  return 0;
}
