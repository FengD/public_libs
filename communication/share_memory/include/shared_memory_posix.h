// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef COMMUNICATION_SHARE_MEMORY_INCLUDE_SHARE_MEMORY_POSIX_H_
#define COMMUNICATION_SHARE_MEMORY_INCLUDE_SHARE_MEMORY_POSIX_H_

#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <sys/mman.h>
#include <fcntl.h>           /* For O_* constants */
#include <semaphore.h>
#include <string>

namespace itd {
namespace communication {

// Signals a problem with the execution of a SharedMemoryPosix call.
class SharedMemoryException : public std::exception {
 public:
  /**
  *   Construct a SharedMemoryException with a explanatory message.
  *   @param message explanatory message
  *   @param system_msg true if system message (from strerror(errno))
  *   should be postfixed to the user provided message
  */
  SharedMemoryException(const std::string &message, bool system_msg = false) throw();

  /** Destructor.
  * Virtual to allow for subclassing.
  */
  virtual ~SharedMemoryException() throw ();

  /** Returns a pointer to the (constant) error description.
  *  @return A pointer to a \c const \c char*. The underlying memory
  *          is in posession of the \c Exception object. Callers \a must
  *          not attempt to free the memory.
  */
  virtual const char* what() const throw (){  return memory_segment_msg_.c_str(); }

 protected:
  std::string memory_segment_msg_;
};

class SharedMemoryPosix {
 public:
  enum {
    C_READ_ONLY  = O_RDONLY,
    C_READ_WRITE = O_RDWR,
  } CREATE_MODE;

  enum {
    A_READ  = PROT_READ,
    A_WRITE = PROT_WRITE,
  } ATTACH_MODE;

  SharedMemoryPosix(const std::string& segment_name);
  ~SharedMemoryPosix();
  bool Create(size_t size, int mode = C_READ_WRITE);
  bool Attach(int mode = A_READ | A_WRITE);
  bool Detach();
  bool Lock();
  bool UnLock();
  int GetID() {
    return memory_id_;
  }

  void* GetData() {
    return memory_ptr_;
  }

  const void* GetData() const {
    return memory_ptr_;
  }

 private:
  void Clear();
  std::string memory_segment_name_;
  int memory_id_;
  sem_t* memory_segment_id_;
  size_t memory_segment_size_;
  void* memory_ptr_;
};

}  // namespace communication
}  // namespace itd

#endif  // COMMUNICATION_SHARE_MEMORY_INCLUDE_SHARE_MEMORY_POSIX_H_
