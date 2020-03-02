// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef _MODULE_UTIL_H_
#define _MODULE_UTIL_H_

#include <sys/wait.h>
#include <string>
#include <vector>

void calc_time_diff(const struct timespec *lo, const struct timespec *hi, struct timespec *diff);
void printfTime(int32_t time);
void split(const std::string &s, const std::string &seperator, std::vector<std::string> *result);
void getAllFilesInFolder(const std::string& dir_in, std::vector<std::string> *files);

#endif  // _MODULE_UTIL_H_
