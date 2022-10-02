#ifndef XNUM_CORE_HPP
#define XNUM_CORE_HPP

#include <cstdint>
#include <memory>

namespace XNum
{
  template <typename T>
  using Unique = std::unique_ptr<T>;

  template <typename T, typename... Args>
  constexpr Unique<T> CreateUnique(Args&&... args)
  {
    return std::make_unique<T>(std::forward<Args>(args)...);
  }
}

using ULong = uint64_t;
using UInt = uint32_t;
using Int = int32_t;

#define PIMPL                                                                                                          \
  class Implementation;                                                                                                \
  XNum::Unique<Implementation> impl;

#endif // XNUM_CORE_HPP
