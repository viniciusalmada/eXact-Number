#ifndef XNUM_RANDOM_HPP
#define XNUM_RANDOM_HPP

#include "Core.hpp"

#include <random>

namespace XNum
{
  class Random
  {
  public:
    static ULong Int(ULong max = std::numeric_limits<ULong>::max());

  private:
    static std::mt19937 s_random_engine;
  };
} // XNum

#endif // XNUM_RANDOM_HPP
