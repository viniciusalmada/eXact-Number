#ifndef XNUM_STRING_UTILS_HPP
#define XNUM_STRING_UTILS_HPP

#include "Core.hpp"

#include <vector>

namespace XNum::StringUtils
{
  [[nodiscard]] std::tuple<bool, ULong, Int> ConvertToIntegerWithExp(std::string&& numberStr);
} // XNum

#endif // XNUM_STRING_UTILS_HPP
