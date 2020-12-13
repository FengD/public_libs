// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: this module is a log module which used to print logs
// Date: 2019-11-22
// Change Log:

#ifndef TOOLS_HLOG_INCLUDE_HLOG_H_
#define TOOLS_HLOG_INCLUDE_HLOG_H_

#include <glog/logging.h>
#include <glog/log_severity.h>
#include <stdint.h>

namespace itd {
namespace tools {
class HLog {
 public:
  static HLog *GetInstance();
  static void DeleteInstance();
  int32_t InitHLog(const char* log_init,
                   const char* log_file_path = "./lidar_log/",
                   int32_t n_log_severity_to_print = google::GLOG_WARNING,
                   int32_t n_log_severity_to_file = google::GLOG_INFO);
  void HLogMsg(const int32_t& n_log_severity, const char *format, ...);

 private:
  HLog();
  ~HLog();
  HLog(const HLog&) = delete;
  const HLog& operator=(const HLog&) = delete;
  static HLog* instance_;
  char p_log_buf_[512];
};

#define LOGINIT(...) itd::tools::HLog::GetInstance()->InitHLog(__VA_ARGS__);
#define LOGINFO(...) itd::tools::HLog::GetInstance()->HLogMsg(0, __VA_ARGS__);
#define LOGWARNING(...) itd::tools::HLog::GetInstance()->HLogMsg(1, __VA_ARGS__);
#define LOGERROR(...) itd::tools::HLog::GetInstance()->HLogMsg(2, __VA_ARGS__);
#define LOGFATAL(...) itd::tools::HLog::GetInstance()->HLogMsg(3, __VA_ARGS__);
}  // namespace tools
}  // namespace itd

#endif  // TOOLS_HLOG_INCLUDE_HLOG_H_
