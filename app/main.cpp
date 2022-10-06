#include <Number.hpp>
#include <iostream>

int main()
{
  const XNum::Number num1{ 2, 3 };
  const XNum::Number num2{ 3, 5 };
  const XNum::Number num3 = num2 / num1;
  std::cout << num1 << " * " << num2 << " = " << num3 << std::endl;

  return 0;
}