#include <cassert>
#include <vector>

#include "src/vector.hpp"

int main() {
  // Arrange
  LinearAlgebra::Vector vector1({1, 2, 3});
  LinearAlgebra::Vector vector2({-1, 5, -7});

  // Act
  const auto result = vector1 + vector2;

  // Assert
  assert(result(0) == 0);
  assert(result(1) == 7);
  assert(result(2) == -4);

  return 0;
}