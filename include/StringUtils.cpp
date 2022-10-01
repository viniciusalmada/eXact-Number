// clang-format off
#include "xnumpch.hpp"
// clang-format on

#include "StringUtils.hpp"

namespace XNum
{
  std::vector<std::string> StringUtils::SplitDecNumber(const std::string& numberStr)
  {
    int count_dots = 0;
    uint64_t find_index = numberStr.find('.');
    while (find_index != std::string::npos)
    {
      count_dots++;
      find_index = numberStr.find('.', find_index + 1);
    }

    if (count_dots > 1)
      return {};

    if (count_dots == 0)
      return { numberStr };

    auto dot_index = numberStr.find('.');
    std::string integer = numberStr.substr(0, dot_index);
    if (integer.empty())
      integer = "0";
    std::string decimal = numberStr.substr(dot_index + 1, numberStr.size());

    return { integer, decimal };
  }
} // XNum