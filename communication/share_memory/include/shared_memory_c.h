// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef COMMUNICATION_SHARE_MEMORY_INCLUDE_SHARED_MEMORY_C_H_
#define COMMUNICATION_SHARE_MEMORY_INCLUDE_SHARED_MEMORY_C_H_

#include <sys/shm.h>
#include <string>

namespace itd {
namespace communication {

template<typename T>
class SharedMemoryC {
 private:
  void CreateShareMemory(const int &key) {
    share_memory_id_ = shmget((key_t)key, sizeof(T), 0666 | IPC_CREAT);
    if (share_memory_id_ == -1) {
      perror("shmget failed\n");
      exit(1);
    }

    shm = shmat(share_memory_id_, 0, 0);
    if (share_memory_ == (void*) - 1) {
      perror("shmat failed\n");
      exit(1);
    }

    share_memory_ = (T *)shm;
  }

  T *share_memory_;
  int share_memory_id_;
  void *shm;

 public:
  explicit SharedMemoryC(const int &key) {
    CreateShareMemory(key);
  }

  ~SharedMemoryC() {
    if (shmdt(share_memory_) == -1) {
      printf("shmdt failed\n");
      exit(EXIT_FAILURE);
    }

    if (shmctl(share_memory_id_, IPC_RMID, 0) == -1) {
      printf("shmctl(IPC_RMID) failed\n");
      exit(EXIT_FAILURE);
    }
  }

  T *GetSharedMemory() {
    return share_memory_;
  }
};
}  // namespace communication
}  // namespace itd

#endif  // COMMUNICATION_SHARE_MEMORY_INCLUDE_SHARED_MEMORY_C_H_
