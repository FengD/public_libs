// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This module is used to check the memory problems
// Date: 2020-03-02
// Change Log:

#include "tracer.h"

namespace itd {
namespace tools {

Tracer::Tracer(void) {
  pthread_mutexattr_t mattr;
  pthread_mutexattr_init(&mattr);
  pthread_mutexattr_settype(&mattr , PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&m_mtx, &mattr);
}

Tracer::~Tracer(void) {
  Dump();
  pthread_mutex_destroy(&m_mtx);
}

void Tracer::AddTrack(void* addr, const char *fname, int32_t lnum) {
  lock();
  tracer[addr] = CAllocLocalInfo(fname, lnum);
  unlock();
}

void Tracer::RemoveTrack(void* addr) {
  lock();
  iterator itor = tracer.find(addr);
  if (itor != tracer.end())
    tracer.erase(itor);
  unlock();
}

void Tracer::Dump() {
  if (tracer.size() != 0) {
    int32_t size = tracer.size();
    printf("%d memory leaks detected\n", size);
    for (iterator itor = tracer.begin(); itor != tracer.end(); ++itor) {
        char const* file = itor->second.File();
        int32_t line = itor->second.Line();
        printf("%s [%d]\n", file, line);
    }
  }
}

}  // namespace tools
}  // namespace itd
