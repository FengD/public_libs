// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include <pcl/point_cloud.h>
#include <pcl/common/common.h>
#include "synchronized_queue.h"

template class itd::SynchronizedQueue<pcl::PointCloud<pcl::PointXYZI>>;
