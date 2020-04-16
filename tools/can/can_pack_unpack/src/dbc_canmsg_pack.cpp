/**
* Copyright (C) 2019 Hirain Technologies
* License: Modified BSD Software License Agreement
* Author: Feng DING
* Description:
*/

#include "dbc_canmsg_pack.h"
#include <math.h>

#define BITCALCULATEPACK(type) \
data[startIndex] = data[startIndex] | (uint8_T)((uint8_T) \
  ((type)(packedValue & (type)(((type)(1)) << i)) >> i)<< leftShift);

#define TYPECALCULATEBITUNPACK(type) \
if (s.dataType) {\
  for (int i = 0; i < s.length; i++) {\
    BITCALCULATEPACK(type);\
    leftShift++;\
    if (leftShift == 8) {\
      leftShift = 0;\
      startIndex++;\
    }\
  }\
} else {\
  for (int i = 0; i < s.length; i++) {\
    BITCALCULATEPACK(type);\
    leftShift++;\
    if (leftShift == 8) {\
      leftShift = 0;\
      startIndex--;\
    }\
  }\
}

#define PACKVALUEUNSIGNED(type)\
type packedValue;\
if (outValue > (real64_T)(max)) {\
  packedValue = (type) max;\
} else if (outValue < (real64_T)(min)) {\
  packedValue = (type) min;\
} else {\
  packedValue = (type) (outValue);\
}\
TYPECALCULATEBITUNPACK(type)

#define PACKVALUESIGNED(type)\
type packedValue;\
type scaledValue;\
scaledValue = (type) (outValue);\
if (scaledValue > (type) (max)) {\
  packedValue = max;\
} else if (scaledValue < (type)(min)) {\
  packedValue = (min);\
} else {\
  packedValue = (type) (scaledValue);\
}\
TYPECALCULATEBITUNPACK(type)

#define DELTA 0.0001

namespace itd {
namespace tools {
namespace can {

int packCanmsg (const Message &m, const size_t &valueSize, const double *value, Canmsg *msg) {
   // if the message has the correct number of signals
  if (valueSize != m.signals.size()) {
    printf("[%ld] value given error\n", m.id);
    return SIGNAL_SIZE_MISMATCH;
  }
  msg->id = m.id;
  msg->length = m.length;
  int index = 0;
  std::for_each(m.signals.begin(), m.signals.end(), [&](Signal s){
    packSignal(s, value[index], msg->data);
    index++;
  });
  return PACK_UNPACK_SUCCESS;
}

void packSignal (const Signal &s, const double &value, uint8_T *data) {
   // --------------- START Packing Signal ------------------
   //   startBit                = s.startBit
   //   length                  = s.length
   //   desiredSignalByteLayout = s.dataType
   //   dataType                = s.is_unsigned
   //   factor                  = s.factor
   //   offset                  = s.offset
   //   minimum                 = s.maximum
   //   maximum                 = s.minimum
   //  -----------------------------------------------------------------------
  {
    real64_T outValue = 0;
    {
      real64_T result = value;
       // check the maximum & minimum
      if (fabs(s.minimum - 0.0) > DELTA || fabs(s.maximum - 0.0) > DELTA) {
        result = result < s.minimum ? s.minimum : result;
        result = result > s.maximum ? s.maximum : result;
      }

      result = (result - s.offset) / s.factor;
      outValue = round(result);
    }

    int startBit = s.startBit;
    {
       // if the motolora type <BEGENDIAN> the startbit needs to be recalculated
      if (!s.dataType) {
        int tmp1 = startBit / 8;
        int tmp2 = tmp1 * 8 + 7 - (startBit % 8) + s.length - 1;
        int tmp3 = tmp2 / 8;
        startBit = tmp3 * 8 + 7 - tmp2 % 8;
      }
    }

    int startIndex = startBit / 8;
    int leftShift = startBit % 8;
     // pack the value by the type
    if (s.is_unsigned) {
      long max = pow(2, s.length) - 1;
      long min = 0;
      if (s.length <= 8) {
        PACKVALUEUNSIGNED(uint8_T);
      } else if (s.length > 8 && s.length <= 16) {
        PACKVALUEUNSIGNED(uint16_T);
      } else if (s.length > 16 && s.length <= 32) {
        PACKVALUEUNSIGNED(uint32_T);
      } else if (s.length > 32) {
        PACKVALUEUNSIGNED(uint64_T);
      }
    } else {
      long max = pow(2, s.length) / 2 - 1;
      long min = (-1) * max - 1;
      if (s.length <= 8) {
        PACKVALUESIGNED(int8_T);
      } else if (s.length > 8 && s.length <= 16) {
        PACKVALUESIGNED(int16_T);
      } else if (s.length > 16 && s.length <= 32) {
        PACKVALUESIGNED(int32_T);
      } else if (s.length > 32) {
        PACKVALUESIGNED(int64_T);
      }
    }
  }
}

}  // namespace can
}  // namespace tools
}  // namespace itd
