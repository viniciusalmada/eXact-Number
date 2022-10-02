// clang-format off
#include <gtest/gtest.h>
// clang-format on

#include "StringUtils.hpp"

TEST(StringUtils, ConvertToIntegerWithExp)
{
  {
    auto [is_neg, num, exp] = XNum::StringUtils::ConvertToIntegerWithExp("123.143");
    
    EXPECT_FALSE(is_neg);
    EXPECT_EQ(num, 123143);
    EXPECT_EQ(exp, 3);
  }
  {
    auto [is_neg, num, exp] = XNum::StringUtils::ConvertToIntegerWithExp("-123.143");
    
    EXPECT_TRUE(is_neg);
    EXPECT_EQ(num, 123143);
    EXPECT_EQ(exp, 3);
  }
  {
    auto [is_neg, num, exp] = XNum::StringUtils::ConvertToIntegerWithExp("-123.01143");
    
    EXPECT_TRUE(is_neg);
    EXPECT_EQ(num, 12301143);
    EXPECT_EQ(exp, 5);
  }
  {
    auto [is_neg, num, exp] = XNum::StringUtils::ConvertToIntegerWithExp("-123.0114300");
    
    EXPECT_TRUE(is_neg);
    EXPECT_EQ(num, 12301143);
    EXPECT_EQ(exp, 5);
  }
  {
    auto [is_neg, num, exp] = XNum::StringUtils::ConvertToIntegerWithExp("-123.011430020");
    
    EXPECT_TRUE(is_neg);
    EXPECT_EQ(num, 12301143002);
    EXPECT_EQ(exp, 8);
  }
  {
    auto [is_neg, num, exp] = XNum::StringUtils::ConvertToIntegerWithExp("-123011430020");
    
    EXPECT_TRUE(is_neg);
    EXPECT_EQ(num, 123011430020);
    EXPECT_EQ(exp, 0);
  }
  {
    auto [is_neg, num, exp] = XNum::StringUtils::ConvertToIntegerWithExp("-0.123011430020");
    
    EXPECT_TRUE(is_neg);
    EXPECT_EQ(num, 12301143002);
    EXPECT_EQ(exp, 11);
  }
}