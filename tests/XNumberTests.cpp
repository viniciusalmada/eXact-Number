// clang-format off
#include <gtest/gtest.h>
// clang-format on

#include "Number.hpp"

TEST(XNumberTests, SimpleCase)
{
  XNum::Number num{ "-514.134" };

  EXPECT_EQ(num.Numerator(), 257067);
  EXPECT_EQ(num.Denominator(), 500);
}

TEST(XNumberTests, SumOperator)
{
  {
    XNum::Number n1{ 37, 5 };
    XNum::Number n2{ 41, 7 };

    XNum::Number res = n1 + n2;
    EXPECT_EQ(res.Numerator(), 464);
    EXPECT_EQ(res.Denominator(), 35);
  }
  {
    XNum::Number n1{ 37, 5, true };
    XNum::Number n2{ 41, 7 };

    XNum::Number res = n1 + n2;
    EXPECT_EQ(res.Numerator(), 54);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_TRUE(res.IsNegative());
  }
  {
    XNum::Number n1{ 37, 5 };
    XNum::Number n2{ 41, 7, true };

    XNum::Number res = n1 + n2;
    EXPECT_EQ(res.Numerator(), 54);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_FALSE(res.IsNegative());
  }
  {
    XNum::Number n1{ 37, 5, true };
    XNum::Number n2{ 41, 7, true };

    XNum::Number res = n1 + n2;
    EXPECT_EQ(res.Numerator(), 464);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_TRUE(res.IsNegative());
  }
}

TEST(XNumberTests, MinusOperator)
{
  {
    XNum::Number n1{ 37, 5 };
    XNum::Number n2{ 41, 7 };

    XNum::Number res = n1 - n2;
    EXPECT_EQ(res.Numerator(), 54);
    EXPECT_EQ(res.Denominator(), 35);
  }
  {
    XNum::Number n1{ 37, 5, true };
    XNum::Number n2{ 41, 7 };

    XNum::Number res = n1 - n2;
    EXPECT_EQ(res.Numerator(), 464);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_TRUE(res.IsNegative());
  }
  {
    XNum::Number n1{ 37, 5 };
    XNum::Number n2{ 41, 7, true };

    XNum::Number res = n1 - n2;
    EXPECT_EQ(res.Numerator(), 464);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_TRUE(res.IsPositive());
  }
  {
    XNum::Number n1{ 37, 5, true };
    XNum::Number n2{ 41, 7, true };

    XNum::Number res = n1 - n2;
    EXPECT_EQ(res.Numerator(), 54);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_TRUE(res.IsNegative());
  }
}

TEST(XNumberTests, MultiOperator)
{
  {
    XNum::Number n1{ 37, 5 };
    XNum::Number n2{ 41, 7 };

    XNum::Number res = n1 * n2;
    EXPECT_EQ(res.Numerator(), 1517);
    EXPECT_EQ(res.Denominator(), 35);
  }
  {
    XNum::Number n1{ 37, 5, true };
    XNum::Number n2{ 41, 7 };

    XNum::Number res = n1 * n2;
    EXPECT_EQ(res.Numerator(), 1517);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_TRUE(res.IsNegative());
  }
  {
    XNum::Number n1{ 37, 5 };
    XNum::Number n2{ 41, 7, true };

    XNum::Number res = n1 * n2;
    EXPECT_EQ(res.Numerator(), 1517);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_TRUE(res.IsNegative());
  }
  {
    XNum::Number n1{ 37, 5, true };
    XNum::Number n2{ 41, 7, true };

    XNum::Number res = n1 * n2;
    EXPECT_EQ(res.Numerator(), 1517);
    EXPECT_EQ(res.Denominator(), 35);
    EXPECT_TRUE(res.IsPositive());
  }
}

TEST(XNumberTests, DivOperator)
{
  {
    XNum::Number n1{ 37, 5 };
    XNum::Number n2{ 41, 7 };

    XNum::Number res = n1 / n2;
    EXPECT_EQ(res.Numerator(), 259);
    EXPECT_EQ(res.Denominator(), 205);
  }
  {
    XNum::Number n1{ 37, 5, true };
    XNum::Number n2{ 41, 7 };

    XNum::Number res = n1 / n2;
    EXPECT_EQ(res.Numerator(), 259);
    EXPECT_EQ(res.Denominator(), 205);
    EXPECT_TRUE(res.IsNegative());
  }
  {
    XNum::Number n1{ 37, 5 };
    XNum::Number n2{ 41, 7, true };

    XNum::Number res = n1 / n2;
    EXPECT_EQ(res.Numerator(), 259);
    EXPECT_EQ(res.Denominator(), 205);
    EXPECT_TRUE(res.IsNegative());
  }
  {
    XNum::Number n1{ 37, 5, true };
    XNum::Number n2{ 41, 7, true };

    XNum::Number res = n1 / n2;
    EXPECT_EQ(res.Numerator(), 259);
    EXPECT_EQ(res.Denominator(), 205);
    EXPECT_TRUE(res.IsPositive());
  }
}