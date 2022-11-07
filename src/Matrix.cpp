// clang-format off
#include "xnumpch.hpp"
// clang-format on

#include "Matrix.hpp"

#include <map>
#include <vector>

namespace XNum
{
  class Matrix::Implementation
  {
  public:
    Implementation(ui64 rows, ui64 columns) : m_rows_counter(rows), m_columns_counter(columns) {}

    ui64 m_rows_counter;
    ui64 m_columns_counter;
    std::map<std::pair<ui64, ui64>, Number> m_data{};
  };

  Matrix::Matrix(ui64 rows, ui64 columns) : impl(CreateUnique<Implementation>(rows, columns)) {}

  Matrix::~Matrix() = default;

  const Number& Matrix::operator[](std::pair<ui64, ui64> positions) const
  {
    if (impl->m_data.count(positions) == 0)
      return Number::ZERO;

    return impl->m_data.at(positions);
  }

  Number& Matrix::operator[](std::pair<ui64, ui64> positions)
  {
    if (impl->m_data.count(positions) == 0)
      impl->m_data.emplace(positions, Number::ZERO);

    return impl->m_data.at(positions);
  }

  Matrix Matrix::operator-() const
  {
    Matrix other = *this;
    std::for_each(other->impl->m_data.cbegin(),
                  other->impl->m_data.cend(),
                  [](const Number& number)
                  {
                    number
                  })
  }

  Matrix::Matrix(const Matrix& matrix)
  {
    std::swap(matrix.impl, this->impl);
  }

} // XNum