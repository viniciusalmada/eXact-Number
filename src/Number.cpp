// clang-format off
#include "xnumpch.hpp"
// clang-format on

#include "Number.hpp"

#include "StringUtils.hpp"

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

    bool is_negative = false;
    ULong numerator = 0;
    ULong denominator = 1;
  };

  Number::Number(std::string&& num) : impl(CreateUnique<Implementation>(std::move(num))) {}

  Number::~Number() = default;

  const ULong& Number::GetNumerator() const
  {
    return impl->numerator;
  }

  const ULong& Number::GetDenominator() const
  {
    return impl->denominator;
  }

} // XNum