// clang-format off
#include "xnumpch.hpp"
// clang-format on

#include "Number.hpp"

#include "StringUtils.hpp"

namespace
{
  XNum::Number SumNumbers(const XNum::Number& lhs, const XNum::Number& rhs)
  {
    auto minimum_multiple = std::lcm(lhs.Denominator(), rhs.Denominator());

    ULong new_denominator = lhs.Denominator() * minimum_multiple;
    ULong new_numerator_1 = (new_denominator / lhs.Denominator()) * lhs.Numerator();
    ULong new_numerator_2 = (new_denominator / rhs.Denominator()) * rhs.Numerator();

    ULong result_numerator;
    bool is_neg;
    if (lhs.IsPositive() && rhs.IsPositive())
    {
      result_numerator = new_numerator_1 + new_numerator_2;
      is_neg = false;
    }
    else if (lhs.IsNegative() && rhs.IsNegative())
    {
      result_numerator = new_numerator_1 + new_numerator_2;
      is_neg = true;
    }
    else
    {
      auto [minor, major] = std::minmax(new_numerator_1, new_numerator_2);
      result_numerator = major - minor;

      is_neg = new_numerator_1 > new_numerator_2 ? lhs.IsNegative() : rhs.IsNegative();
    }

    return { result_numerator, new_denominator, is_neg };
  }
}

namespace XNum
{
  class Number::Implementation
  {
  private:
    void Reduce()
    {
      if (numerator == 0)
        return;
      auto maximum_divisor = std::gcd(numerator, denominator);
      numerator /= maximum_divisor;
      denominator /= maximum_divisor;
    }

  public:
    explicit Implementation(std::string&& numberStr)
    {
      auto [is_neg, num, exp] = XNum::StringUtils::ConvertToIntegerWithExp(std::move(numberStr));
      this->is_negative = is_neg;
      this->numerator = num;
      this->denominator = static_cast<ULong>(std::powl(10, exp));

      Reduce();
    }

    explicit Implementation(ULong numerator, ULong denominator, bool isNeg) :
        numerator(numerator),
        denominator(denominator),
        is_negative(isNeg)
    {
      Reduce();
    }

    ULong numerator = 0;
    ULong denominator = 1;
    bool is_negative = false;
  };

  Number::Number(std::string&& num) : impl(CreateUnique<Implementation>(std::move(num))) {}

  Number::Number(ULong numerator, ULong denominator, bool isNeg) :
      impl(CreateUnique<Implementation>(numerator, denominator, isNeg))
  {
  }

  Number::~Number() = default;

  const ULong& Number::Numerator() const
  {
    return impl->numerator;
  }

  const ULong& Number::Denominator() const
  {
    return impl->denominator;
  }

  Number Number::operator+(const Number& other) const
  {
    if (other.Numerator() == 0)
      return { *this };

    if (this->Numerator() == 0)
      return other;

    return SumNumbers(*this, other);
  }

  Number Number::operator-(const Number& other) const
  {
    if (other.Numerator() == 0)
      return { *this };

    if (this->Numerator() == 0)
      return -other;

    return SumNumbers(*this, -other);
  }

  Number Number::operator*(const Number& other) const
  {
    if (other.Numerator() == 0)
      return { other };

    if (this->Numerator() == 0)
      return { *this };

    ULong new_numerator = this->Numerator() * other.Numerator();
    ULong new_denominator = this->Denominator() * other.Denominator();
    bool is_neg = this->IsNegative() & other.IsPositive() || this->IsPositive() & other.IsNegative();

    return { new_numerator, new_denominator, is_neg };
  }

  Number Number::operator/(const Number& other) const
  {
    if (other.Numerator() == 0)
      throw std::runtime_error{ "Divisor equal zero!" };

    if (this->Numerator() == 0)
      return { *this };

    Number divisor_inv = other.Inverse();

    return *this * divisor_inv;
  }

  bool Number::IsPositive() const
  {
    return !impl->is_negative && Numerator() != 0;
  }

  bool Number::IsNegative() const
  {
    return impl->is_negative && Numerator() != 0;
  }

  Number::Number(const Number& other) : Number(other.Numerator(), other.Denominator(), other.IsNegative()) {}

  Number& Number::operator=(Number other)
  {
    std::swap(impl, other.impl);
    return *this;
  }

  Number Number::operator-() const
  {
    return { this->Numerator(), this->Denominator(), !this->IsNegative() };
  }

  std::ostream& operator<<(std::ostream& out, const Number& number)
  {
    if (number.Denominator() == 1u)
      out << number.Numerator();
    else
      out << number.Numerator() << '/' << number.Denominator();
    return out;
  }

  Number& Number::Inverse()
  {
    std::swap(impl->numerator, impl->denominator);
    return *this;
  }

  Number Number::Inverse() const
  {
    std::swap(impl->numerator, impl->denominator);
    return *this;
  }

} // XNum