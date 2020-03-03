#ifndef _MODULE_TOOLS_TRACER_H_
#define _MODULE_TOOLS_TRACER_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string>
#include <map>
#include <list>
#include <string.h>
#include <assert.h>
#define DEBUG

namespace itd {
namespace tools {

struct StMemAllocRec {
  void* addr;
  size_t nSize;
};

class CAllocLocalInfo {
 public:
  CAllocLocalInfo(char const * file, int32_t line) : _file (file), _line (line) {}
  CAllocLocalInfo() : _file (0), _line (0) {}
  char const * File() const { return _file; }
  int32_t Line() const { return _line; }

 private:
  char const * _file;
  int32_t _line;
};

class Tracer {
 private:
  Tracer(void);
  ~Tracer(void);

 public:
  static Tracer& GetInstance() {
    static Tracer inst;
    return inst;
  }

  void AddTrack(void* addr, const char *fname, int32_t lnum);
  void RemoveTrack(void* addr);

 protected:

  void Dump();
  void lock() {
    pthread_mutex_lock(&m_mtx);
  }

  void unlock() {
    pthread_mutex_unlock(&m_mtx);
  }

protected:
  typedef std::map<void *, CAllocLocalInfo>::iterator iterator;
  std::map<void *,CAllocLocalInfo> tracer;
  pthread_mutex_t m_mtx;
};


}  // namespace tools
}  // namespace itd

inline void * operator new(size_t size, const char* file, const size_t line) {
  void *ptr = malloc(size);
  itd::tools::Tracer::GetInstance().AddTrack(ptr, file, line);
  return ptr;
}

inline void * operator new [](size_t size, const char* file, const size_t line) {
  void *ptr = malloc(size);
  itd::tools::Tracer::GetInstance().AddTrack(ptr, file, line);
  return ptr;
}

inline void operator delete(void *p) {
  itd::tools::Tracer::GetInstance().RemoveTrack(p);
  free(p);
}

inline void operator delete [](void *p) {
  itd::tools::Tracer::GetInstance().RemoveTrack(p);
  free(p);
}

inline void operator delete [](void *p, const char* file, const size_t line) {
  (void) file;
  (void) line;
  itd::tools::Tracer::GetInstance().RemoveTrack(p);
  free(p);
}


#ifdef DEBUG
#define malloc(s) ((void*)new unsigned char[s])
#define free(p)   (delete [] (char*)(p));
#define new new(__FILE__, __LINE__)
#endif

#endif  // _MODULE_TOOLS_TRACER_H_
