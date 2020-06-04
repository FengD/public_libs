// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: Can msg define
// Date: 2019-11-22
// Change Log:

#ifndef TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_CANMSG_DEFINE_H_
#define TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_CANMSG_DEFINE_H_

#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

struct Signal {
  std::string name;
  int startBit;
  int length;
  double factor;
  double offset;
  double maximum;
  double minimum;
  int dataType;
  int is_unsigned;
  std::string unit;

  bool operator <(const Signal& s) const {
      return startBit < s.startBit;
  }

  bool operator >(const Signal& s) const {
      return startBit > s.startBit;
  }
};

struct Message {
  int64_t id;
  std::string name;
  int length;
  std::vector<Signal> signals;

  bool operator <(const Message& msg) const {
      return id < msg.id;
  }

  bool operator >(const Message& msg) const {
      return id > msg.id;
  }
};

struct Canmsg {
  int64_t id;
  int  length;
  uint8_t  data[8];
};

enum PackUnpackStat {
  SIGNAL_SIZE_MISMATCH = -3,
  UNPACK_ID_MISMATCH = -2,
  UNPACK_LENGTH_MISMATCH = -1,
  PACK_UNPACK_SUCCESS = 0
};

#endif  // TOOLS_CAN_CAN_PACK_UNPACK_INCLUDE_CANMSG_DEFINE_H_
