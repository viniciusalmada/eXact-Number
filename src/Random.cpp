#include "Random.hpp"

namespace XNum
{
  std::mt19937 Random::s_random_engine{ std::random_device{}() };

  ULong Random::Int(ULong max)
  {
    std::uniform_int_distribution<ULong> distribution{ 0, max };
    return distribution(s_random_engine);
  }

} // XNum
