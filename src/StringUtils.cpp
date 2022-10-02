// clang-format off
#include "xnumpch.hpp"
// clang-format on

#include "StringUtils.hpp"

namespace XNum::StringUtils
{
  std::tuple<bool, ULong, Int> ConvertToIntegerWithExp(std::string&& numberStr)
  {
    // Check for number with more than 1 dot
    int count_dots = 0;
    uint64_t find_index = numberStr.find('.');
    while (find_index != std::string::npos)
    {
      count_dots++;
      find_index = numberStr.find('.', find_index + 1);
    }
    bool is_neg = false;
    if (numberStr.front() == '-')
    {
      is_neg = true;
      numberStr.erase(numberStr.begin(), numberStr.begin() + 1);
    }

    if (count_dots > 1)
      return { is_neg, 0, 0 };

    // Number without dot
    if (count_dots == 0)
      return { is_neg, std::stoull(numberStr), 0 };

    Int zeros_on_end = 0;
    for (auto rev_itr = numberStr.rbegin(); rev_itr != numberStr.rend(); rev_itr++)
    {
      if (*rev_itr == '0')
      {
        zeros_on_end++;
        continue;
      }
      break;
    }
    numberStr.erase(numberStr.end() - zeros_on_end, numberStr.end());
    UInt dot_pos = numberStr.find('.');
    UInt exp = numberStr.size() - dot_pos - 1;

    std::erase(numberStr, '.');
    ULong number = std::stoull(numberStr);

    return { is_neg, number, exp };
  }
} // XNum