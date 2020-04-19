#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "mqtt_subscriber.h"

#define HOST "192.168.8.210"
#define PORT  1885
#define KEEP_ALIVE 60

void OnMessage(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg) {
  (void)(mosq);
  (void)(obj);
  printf("%d %s\n", msg->payloadlen, (char *)msg->payload);
}

int main() {
  itd::communication::MqttSubscriber *sub;
  sub = new itd::communication::MqttSubscriber(KEEP_ALIVE, HOST, PORT);
  sub->Subscribe(true, "Test", OnMessage);
  return 0;
}
