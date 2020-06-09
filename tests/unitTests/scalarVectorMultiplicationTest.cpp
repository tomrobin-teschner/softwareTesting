#include <cassert>
#include <vector>

#include "src/vector.hpp"

int main() {
  // Arrange
  LinearAlgebra::Vector vector({1, 2, 3});
  const double scaleFactor = 2;

  // Act
  const auto scaledVector = scaleFactor * vector;

  // Assert
  assert(scaledVector(0) == 2);
  assert(scaledVector(1) == 4);
  assert(scaledVector(2) == 6);

  return 0;
}