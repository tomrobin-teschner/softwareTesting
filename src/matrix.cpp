#include "src/matrix.hpp"

namespace LinearAlgebra {

Matrix::Matrix(const Matrix::MatrixType &inputMatrix) : matrix_(inputMatrix) { }

const double &Matrix::operator()(int rowIndex, int columnIndex) const {
  return matrix_[rowIndex][columnIndex];
}

} // namespace LinearAlgebra