#ifndef XNUM_NUMBER_HPP
#define XNUM_NUMBER_HPP

#include "Core.hpp"

#include <string>

namespace XNum
{
  class Number
  {
  public:
    explicit Number(std::string&& num);
    ~Number();

    const ULong& GetNumerator() const;
    const ULong& GetDenominator() const;

  private:
    PIMPL
  };
} // XNum

#endif // XNUM_NUMBER_HPP
