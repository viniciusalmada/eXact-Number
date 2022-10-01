// clang-format off
#include <gtest/gtest.h>
// clang-format on

#include "StringUtils.hpp"

TEST(StringUtils, StartWithSeparator)
{
  std::string str = ".012";
  std::vector<std::string> res = XNum::StringUtils::SplitDecNumber(str);
  // Expect two strings to be equal.
  EXPECT_EQ(res[0], "0");
  EXPECT_EQ(res[1], "012");
}

TEST(StringUtils, StartWithSeparatorAndHasTwoSeparators)
{
  std::string str = ".0.1";
  std::vector<std::string> res = XNum::StringUtils::SplitDecNumber(str);

  EXPECT_TRUE(res.empty());
}

TEST(StringUtils, StartWithSeparatorAndHasMultipleSeparators)
{
  std::string str = ".0.....123";
  std::vector<std::string> res = XNum::StringUtils::SplitDecNumber(str);

  EXPECT_TRUE(res.empty());
}