#include <cassert>
#include <vector>

#include "src/matrix.hpp"

int main() {
  // Arrange
  LinearAlgebra::Matrix matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  const double scaleFactor = 2.0;

  // Act
  const auto scaledVector = scaleFactor * matrix;

  // Assert
  assert(scaledVector(0, 0) == 2);
  assert(scaledVector(0, 1) == 4);
  assert(scaledVector(0, 2) == 6);

  assert(scaledVector(1, 0) == 8);
  assert(scaledVector(1, 1) == 10);
  assert(scaledVector(1, 2) == 12);

  assert(scaledVector(2, 0) == 14);
  assert(scaledVector(2, 1) == 16);
  assert(scaledVector(2, 2) == 18);

  return 0;
}