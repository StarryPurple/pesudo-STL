#ifndef ISM_EXCEPTIONS_H
#define ISM_EXCEPTIONS_H
#include <string>

namespace insomnia {

class exception {
protected:
  const std::string variant;
  std::string detail;
public:
  exception();
  exception(const exception &ec);
  virtual std::string what();
  virtual ~exception();
};

class index_out_of_bound : public exception {};

class runtime_error : public exception {};

class invalid_iterator : public exception {};

class container_is_empty : public exception {};

}

#endif // ISM_EXCEPTIONS_H