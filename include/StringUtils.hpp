#ifndef XNUM_STRING_UTILS_HPP
#define XNUM_STRING_UTILS_HPP

#include <vector>
namespace XNum
{

  class StringUtils
  {
  public:
    static std::vector<std::string> SplitDecNumber(const std::string& numberStr);
  };

} // XNum

#endif // XNUM_STRING_UTILS_HPP
