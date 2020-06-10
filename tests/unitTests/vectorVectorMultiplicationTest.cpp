#include <cassert>
#include <vector>

#include "src/vector.hpp"

int main() {
  // Arrange
  LinearAlgebra::Vector vector1({-1, 3, 9});
  LinearAlgebra::Vector vector2({6, -2, 6});

  // Act
  const auto result = vector1.transpose() * vector2;

  // Assert
  assert(result == 42);

  return 0;
}