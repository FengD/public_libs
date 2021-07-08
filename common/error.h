// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: DEMING YUAN
// Description: error code

#pragma once

#include <cassert>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

// -------------------------------
// ------ exception classes ------
// -------------------------------

namespace itd {
namespace common {
enum ErrorType { EUNSPECIFIED, EYAML_PARSE };

class Error : public std::exception {
 public:
  Error(ErrorType t, const std::string& a) : info(a), type(t) {}

  explicit Error(ErrorType t) : type(t) {}

  explicit Error(const std::string& a) : info(a), type(EUNSPECIFIED) {}

  Error() : type(EUNSPECIFIED) {}

  virtual ~Error() noexcept {}

  const char* what() const noexcept {
    if (info.size() > 0)
      return info.c_str();
    else
      return type_to_string();
  }

  const char* type_to_string() const noexcept {
    if (type == EUNSPECIFIED)
      return "EUNSPECIFIED";
    else if (type == EYAML_PARSE)
      return "EYAML_PARSE";
    else
      return "undefined Error type";
  }

  const std::string info;  // info about the Error
  const ErrorType type;   // the type of the Error

 private:
  const Error& operator=(const Error&);
};
}  // namespace common
}  // namespace itd
