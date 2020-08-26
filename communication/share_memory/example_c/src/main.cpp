// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include <unistd.h>
#include <pcl/point_cloud.h>
#include <signal.h>
#include <pcl/common/common.h>
#include "shared_memory_c.h"

itd::communication::SharedMemoryC<pcl::PointCloud<pcl::PointXYZI>> *test;
void ctrlhandler(int a) {
  (void) a;
  delete test;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("No param given! Should be <read> or <write>\n");
    return 0;
  }

  signal(SIGINT, ctrlhandler);
  test = new itd::communication::SharedMemoryC<pcl::PointCloud<pcl::PointXYZI>>(2000);
  pcl::PointCloud<pcl::PointXYZI> *cloud = test->GetSharedMemory();
  if (std::string(argv[1]) == "write") {
    printf("write\n");
    while (1) {
      pcl::PointXYZI a;
      cloud->push_back(a);
      printf("%d\n", cloud->size());
      usleep(10000);
    }
  } else if (std::string(argv[1]) == "read") {
    printf("read\n");
    while (1) {
      printf("%d\n", cloud->size());
      usleep(100000);
    }
  }

  return 0;
}
