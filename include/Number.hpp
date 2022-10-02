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
    Number(ULong numerator, ULong denominator, bool isNeg = false);
    Number(const Number& other);
    ~Number();

    Number& operator=(Number other);

    [[nodiscard]] const ULong& Numerator() const;
    [[nodiscard]] const ULong& Denominator() const;
    [[nodiscard]] bool IsPositive() const;
    [[nodiscard]] bool IsNegative() const;
    Number Inverse() const;

    Number operator-() const;
    Number operator+(const Number& other) const;
    Number operator-(const Number& other) const;
    Number operator*(const Number& other) const;
    Number operator/(const Number& other) const;

  private:
    PIMPL
  };
} // XNum

#endif // XNUM_NUMBER_HPP
