// clang-format off
#include <gtest/gtest.h>
// clang-format on

#include "Number.hpp"

TEST(XNumberTests, SimpleCase)
{
  XNum::Number num{ "-514.134" };

  EXPECT_EQ(num.GetNumerator(), 257067);
  EXPECT_EQ(num.GetDenominator(), 500);
}