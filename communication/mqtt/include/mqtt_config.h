// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#ifndef COMMUNICATION_MQTT_INCLUDE_MQTT_CONFIG_H_
#define COMMUNICATION_MQTT_INCLUDE_MQTT_CONFIG_H_

#include <string>
#include <functional>

namespace itd {
namespace communication {

struct mosq_config {
	std::string host;
	int port;
	std::string username;
	std::string password;

  explicit mosq_config(std::string host = "",
                       int port = 0,
                       std::string username = "",
                       std::string password = "") :
                       host(host), port(port),
                       username(username), password(password) {}

  mosq_config& operator= (const mosq_config& m) {
    host = m.host;
    port = m.port;
    username = m.username;
    password = m.password;
    return *this;
  }
};

#ifdef __AVR__
  typedef void (*PublishCallback)(int mid);
  typedef void (*LogCallback)(const char *str);
  typedef void (*MessageCallback)(int payloadlen, const void *payload);
  typedef void (*SubscribeCallback)(int mid, int qos_count);
  typedef void (*UnsubscribeCallback)(int mid);
#else
  typedef std::function<void(int mid)> PublishCallback;
  typedef std::function<void(int level, const char *str)> LogCallback;
  typedef std::function<void(int payloadlen, const void *payload)> MessageCallback;
  typedef std::function<void(int mid, int qos_count)> SubscribeCallback;
  typedef std::function<void(int mid)> UnsubscribeCallback;
#endif

}  // namespace communication
}  // namespace itd

#endif  // COMMUNICATION_MQTT_INCLUDE_MQTT_CONFIG_H_
