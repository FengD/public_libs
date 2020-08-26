#include "shared_memory_posix.h"
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <cstdio>
#include <cstdlib>
#define SEMAPHORE_NAME "semaphoreInit"

namespace itd {
namespace communication {
SharedMemoryPosix::SharedMemoryPosix( const std::string& segment_name ) :
  memory_segment_name_(segment_name),
  memory_id_(-1),
  memory_segment_id_(NULL),
  memory_segment_size_(0),
  memory_ptr_(NULL) {
  memory_segment_id_ = sem_open(SEMAPHORE_NAME, O_CREAT, S_IRUSR | S_IWUSR, 1);
}

bool SharedMemoryPosix::Create(size_t size, int mode) {
   memory_segment_size_ = size;
   memory_id_ = shm_open(memory_segment_name_.c_str(), O_CREAT | mode, S_IRWXU | S_IRWXG);
   if (memory_id_ < 0) {
      switch (errno) {
      case EACCES:
        throw SharedMemoryException("Permission Exception ");
        break;
      case EEXIST:
        throw SharedMemoryException("Shared memory object specified by name already exists.");
        break;
      case EINVAL:
        throw SharedMemoryException("Invalid shared memory name passed.");
        break;
      case EMFILE:
        throw SharedMemoryException("The process already has the maximum number of files open.");
        break;
      case ENAMETOOLONG:
        throw SharedMemoryException("The length of name exceeds PATH_MAX.");
        break;
      case ENFILE:
        throw SharedMemoryException("The limit on the total number of files open on the system has been reached");
        break;
      default:
        throw SharedMemoryException("Invalid exception occurred in shared memory creation");
        break;
      }
   }
   // adjusting mapped file size (make room for the whole segment to map)
   ftruncate(memory_id_, memory_segment_size_);
   return true;
}

bool SharedMemoryPosix::Attach(int mode) {
   /* requesting the shared segment    --  mmap() */
   memory_ptr_ = mmap(NULL, memory_segment_size_, mode, MAP_SHARED, memory_id_, 0);
   if (memory_ptr_ == NULL) {
     throw SharedMemoryException("Exception in attaching the shared memory region");
     return false;
   }
   return true;
}

bool SharedMemoryPosix::Detach() {
  return munmap(memory_ptr_, memory_segment_size_);
}

bool SharedMemoryPosix::Lock() {
  return sem_wait(memory_segment_id_);
}

bool SharedMemoryPosix::UnLock() {
  return sem_post(memory_segment_id_);
}

SharedMemoryPosix::~SharedMemoryPosix() {
  Clear();
}

void SharedMemoryPosix::Clear() {
  if (memory_id_ != -1) {
    if (shm_unlink(memory_segment_name_.c_str()) < 0) {
      perror("shm_unlink");
    }
  }
  /**
  * Semaphore unlink: Remove a named semaphore  from the system.
  */
  if (memory_segment_id_ != NULL) {
    /**
    * Semaphore Close: Close a named semaphore
    */
    if (sem_close(memory_segment_id_) < 0) {
      perror("sem_close");
    }
    /**
    * Semaphore unlink: Remove a named semaphore  from the system.
    */
    if (sem_unlink(SEMAPHORE_NAME) < 0) {
      perror("sem_unlink");
    }
  }
}

SharedMemoryException::SharedMemoryException(const std::string &message, bool system_msg) throw() {
  (void) system_msg;
  printf("exception: %s\n", message.c_str());
}

SharedMemoryException::~SharedMemoryException() throw () {}

}  // namespace communication
}  // namespace itd
