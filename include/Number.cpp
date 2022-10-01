#include "Number.hpp"

#include "xnumpch.hpp"

namespace XNum
{
  class Number::Implementation
  {
  public:
    Implementation(std::string&& num){

    }

    ULong numerator;
    ULong denominator;
  };
} // XNum