#ifndef XNUM_NUMBER_HPP
#define XNUM_NUMBER_HPP

#include "Core.hpp"

#include <string>

namespace XNum
{

  class Number
  {
  public:
    Number(std::string&& num);
    ~Number();

  private:
    PIMPL
  };

} // XNum

#endif // XNUM_NUMBER_HPP
