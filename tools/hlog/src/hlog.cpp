// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: this module is a log module which used to print logs
// Date: 2019-11-22
// Change Log:

#include "hlog.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <thread>

namespace itd {
namespace tools {

HLog* HLog::instance_ = new (std::nothrow) HLog;

HLog* HLog::GetInstance() {
  return instance_;
}

void HLog::DeleteInstance() {
  if (instance_) {
    delete instance_;
    instance_ = nullptr;
  }
}

HLog::HLog() {
  memset(p_log_buf_, 0, 512);
}

HLog::~HLog() {}

int32_t HLog::InitHLog(const char* log_init,
                       const char* log_file_path,
                       int32_t n_log_severity_to_print,
                       int32_t n_log_severity_to_file) {
  int32_t ret = 0;
  CHECK_NOTNULL(log_init);

  google::InitGoogleLogging(log_init);

  if (0 != access(log_file_path, 0)) {
    std::string command = log_file_path;
    command = "mkdir -p " + command;
    ret = system(command.c_str());
  }

  google::SetLogDestination(n_log_severity_to_file, log_file_path);
  google::SetStderrLogging(n_log_severity_to_print);
  return ret;
}

void HLog::HLogMsg(const int32_t& n_log_severity, const char *format, ...) {
  va_list arg_ptr;
  va_start(arg_ptr, format);
  vsprintf(p_log_buf_, format, arg_ptr);
  switch (n_log_severity) {
    case 0:
      LOG(INFO) << p_log_buf_;
      break;
    case 1:
      LOG(WARNING) << p_log_buf_;
      break;
    case 2:
      LOG(ERROR) << p_log_buf_;
      break;
    case 3:
      LOG(FATAL) << p_log_buf_;
      break;
    default:
      assert(false);
  }
  va_end(arg_ptr);
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  memset(p_log_buf_, 0, 512);
}
}  // namespace tools
}  // namespace itd
