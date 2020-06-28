// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: dbc file analysis
// Date: 2019-11-22
// Change Log:

#ifndef TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_DBC_FILE_ANALYSIS_H_
#define TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_DBC_FILE_ANALYSIS_H_

#include <pthread.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "canmsg_define.h"

#define MSSAGEHEAD "BO_"
#define SIGNALHEAD "SG_"

namespace itd {
namespace tools {
namespace can {

class DbcAnalysis {
 private:
  DbcAnalysis();
  ~DbcAnalysis();
  DbcAnalysis(const DbcAnalysis&);
  DbcAnalysis& operator=(const DbcAnalysis&);
  void transformMessageFromLine(std::string line, Message& m);
  void transformSignalFromLine(std::string line, Message &m);
  void getPosInfoTypeUnsignedFromStr(std::string str, Signal &s);
  void getFactorOffsetFromStr(std::string str, Signal &s);
  void getMaxMinFromStr(std::string str, Signal &s);
  void getUnitFromStr(std::string str, Signal &s);
  std::map<int64_t, Message> messages_;
  std::vector<std::string> files_;
  static DbcAnalysis* instance_;
  static pthread_mutex_t mutex_;

 public:
  static DbcAnalysis *getInstance();
  void printMessages();
  void analysisFiles();
  void addOneDbcFile(const std::string &filePath);
  std::map<int64_t, Message>& getMessages();
};

}  // namespace can
}  // namespace tools
}  // namespace itd

#endif  // TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_DBC_FILE_ANALYSIS_H_
