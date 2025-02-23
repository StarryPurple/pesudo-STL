#include "ism_exceptions.h"

namespace insomnia {

exception::exception() = default;

exception::exception(const exception &ec) = default;

std::string exception::what() {
  return variant + " " + detail;
}

exception::~exception() = default;


}