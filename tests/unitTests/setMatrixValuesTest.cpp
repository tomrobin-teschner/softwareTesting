#include <cassert>
#include <vector>

#include "src/matrix.hpp"

int main() {
  // Arrange
  LinearAlgebra::Matrix matrix;
  matrix.setSize(2, 3);

  // Act
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;

  matrix(1, 0) = 1.5;
  matrix(1, 1) = 2.5;
  matrix(1, 2) = 3.5;

  // Assert
  assert(matrix.getNumberOfRows() == 2);
  assert(matrix.getNumberOfColumns() == 3);
  assert(matrix(0, 0) == 1.0);
  assert(matrix(0, 1) == 2.0);
  assert(matrix(0, 2) == 3.0);
  assert(matrix(1, 0) == 1.5);
  assert(matrix(1, 1) == 2.5);
  assert(matrix(1, 2) == 3.5);

  return 0;
}