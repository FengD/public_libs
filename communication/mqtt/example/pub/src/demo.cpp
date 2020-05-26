#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "publisher.h"
#include "handler.h"
#include "itd_ipd_sensor_msgs.pb.h"

#define HOST "192.168.8.224"
#define PORT 1883

void OnLog(int level, const char *str) {
  printf("Client log. %d %s\n", level, str);
}

int main() {
  itd::communication::Handler handler(HOST, PORT);
  // itd::communication::Publisher pub = handler.advertise<itd::communication::protobuf::PointCloud>("Test");
  // if need username and password for mqtt server
  // itd::communication::Handler handler(KEEP_ALIVE, HOST, PORT, USERNAME, PASSWORD);
  // if need a callback of log after publish
  itd::communication::Publisher *pub = handler.advertise<itd::communication::protobuf::PointCloud>("Test", OnLog);
  int i = 0;
  while(1) {
    itd::communication::protobuf::PointCloud msg;
    msg.set_height(10);
    msg.set_width(i++);
    pub->Publish(msg);
    usleep(10000);
  }
  return 0;
}
