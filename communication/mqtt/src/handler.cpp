// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "handler.h"

namespace itd {
namespace communication {

Handler::Handler(std::string host, int32_t port,
                 std::string username, std::string password) {
  cfg_.port = port;
  cfg_.host = host;
  cfg_.username = username;
  cfg_.password = password;
}

Handler::~Handler() {}

}  // namespace communication
}  // namespace itd
