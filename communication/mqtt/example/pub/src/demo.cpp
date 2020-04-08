#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "hi_mqtt.h"

#define HOST "localhost"
#define PORT  1883
#define KEEP_ALIVE 60

int main() {
  itd::communication::HiMqtt *client = new itd::communication::HiMqtt();
  client->SetHost(HOST);
  client->SetAliveTime(KEEP_ALIVE);
  client->SetPort(PORT);
  client->Init();
  while(1) {
    printf("ds\n");
    char msg[] = "hahahahahaha";
    client->Publish("test", msg, strlen(msg));
    sleep(1);
  }
  return 0;
}
