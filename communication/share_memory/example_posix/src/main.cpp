// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "shared_memory_posix.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("No param given! Should be <read> or <write>\n");
    return 0;
  }

  try {
    itd::communication::SharedMemoryPosix shmMemory("hello");
    if (shmMemory.Create(4096)) {
      printf("Create success\n");
    }

    if (shmMemory.Attach()) {
      printf("Attach success\n");
    }

    int *test = static_cast<int *>(shmMemory.GetData());
    if (std::string(argv[1]) == "write") {
      printf("write\n");
      int i = 0;
      while (1) {
        *test = i++;
        printf("+++>%d\n", *test);
        usleep(10000);
      }
    } else if (std::string(argv[1]) == "read") {
      printf("read\n");
      while (1) {
        printf("--->%d\n", *test);
        usleep(100000);
      }
    }
  } catch (std::exception& ex) {
    std::cout << "Exception:" << ex.what() << std::endl;
  }
  return 0;
}
