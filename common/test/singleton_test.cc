// Copyright (C) 2021 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: DING Feng
// Description: singleton test

#include "gtest/gtest.h"
#include "common/singleton.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}