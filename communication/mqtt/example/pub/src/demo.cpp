#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string.h>
#include "mqtt_publisher.h"

#define HOST "192.168.8.210"
#define PORT  1883
#define KEEP_ALIVE 60

void OnPublish(struct mosquitto *mosq, void *obj, int rc) {
  (void)(obj);
  (void)(rc);
  (void)(mosq);
  printf("Client publish.\n");
}

void OnLog(struct mosquitto *mosq, void *obj, int rc, const char *xx) {
  (void)(obj);
  (void)(rc);
  (void)(mosq);
  (void)(xx);
  printf("Client log.\n");
}

int main() {
  itd::communication::MqttPublisher *pub;
  pub = new itd::communication::MqttPublisher(KEEP_ALIVE, HOST, PORT, "Test");
  // if need
  pub->SetOnPublish(OnPublish);
  // if need
  pub->SetOnLog(OnLog);
  // if need username and password for mqtt server
  // pub = new itd::communication::MqttPublisher(KEEP_ALIVE, HOST, PORT, "Test", "hirain", "hirain123");

  while(1) {
    printf("ds\n");
    char msg[] = "hahahahahaha";
    pub->Publish(msg, strlen(msg));
    sleep(1);
  }
  return 0;
}
