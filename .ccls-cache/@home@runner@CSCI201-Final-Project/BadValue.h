#ifndef BAD_VALUE_H
#define BAD_VALUE_H

#include <exception>


class BadValue : public std::exception {
public:
  BadValue(char* p_message) {
    message = p_message;
  }

  const char* what() const throw () {
    return message;
  }

private:
  char* message;
};

#endif // BAD_VALUE