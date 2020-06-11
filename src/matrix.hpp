#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

namespace LinearAlgebra {

class Matrix {
public:
  using MatrixType = std::vector<std::vector<double>>;

public:
  Matrix() = default;
  Matrix(const MatrixType &inputMatrix);

  void setSize(const unsigned &rows, const unsigned &columns);
  unsigned getNumberOfRows() const;
  unsigned getNumberOfColumns() const;

  const double &operator()(int rowIndex, int columnIndex) const;
  double &operator()(int rowIndex, int columnIndex);
  Matrix &operator*(const double &scaleFactor);
  friend Matrix &operator*(const double &scaleFactor, Matrix matrix);

private:
  MatrixType matrix_;
};

} // namespace LinearAlgebra

#endif