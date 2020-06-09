#include <cassert>
#include <vector>

#include "src/vector.hpp"

int main() {
  // Arrange
  LinearAlgebra::Vector vector1({1, 2, 3});
  LinearAlgebra::Vector vector2({-1, 5, -7});

  // Act
  const auto result = vector1 - vector2;

  // Assert
  assert(result(0) == 2);
  assert(result(1) == -3);
  assert(result(2) == 10);

  return 0;
}