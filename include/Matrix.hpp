#ifndef XNUM_MATRIX_HPP
#define XNUM_MATRIX_HPP

#include "Number.hpp"

namespace XNum
{
  class Matrix
  {
    Matrix(ui64 rows, ui64 columns);
    Matrix(const Matrix& matrix) const;
    ~Matrix();

    const Number& operator[](std::pair<ui64, ui64> positions) const;
    Number& operator[](std::pair<ui64, ui64> positions);

    Matrix operator-() const;


  private:
    PIMPL
  };
} // XNum

#endif // XNUM_MATRIX_HPP
