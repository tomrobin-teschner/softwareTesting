#include "src/matrix.hpp"

namespace LinearAlgebra {

Matrix::Matrix(const Matrix::MatrixType &inputMatrix) : matrix_(inputMatrix) { }

const double &Matrix::operator()(int rowIndex, int columnIndex) const {
  return matrix_[rowIndex][columnIndex];
}

Matrix &Matrix::operator*(const double &scaleFactor) {
  for (auto &row : matrix_)
    for (auto &entry : row)
      entry *= scaleFactor;
  return *this;
}

Matrix &operator*(const double &scaleFactor, Matrix &matrix) {
  return matrix * scaleFactor;
}

} // namespace LinearAlgebra