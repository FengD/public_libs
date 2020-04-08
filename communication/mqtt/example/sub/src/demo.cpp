#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "hi_mqtt.h"

#define HOST "localhost"
#define PORT  1883
#define KEEP_ALIVE 60

void* my_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message) {
  printf("sdfsdf\n");
  if (message->payloadlen) {
      printf("%s %s", message->topic, message->payload);
  } else {
      printf("%s (null)\n", message->topic);
  }
}

int main() {
  itd::communication::HiMqtt *client = new itd::communication::HiMqtt();
  client->SetHost(HOST);
  client->SetAliveTime(KEEP_ALIVE);
  client->SetPort(PORT);
  client->Init();
  client->Subscribe( "test", std::bind(my_message_callback,
                                       std::placeholders::_1,
                                       std::placeholders::_2,
                                       std::placeholders::_3) );
  return 0;
}
