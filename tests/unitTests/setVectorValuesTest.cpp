#include <cassert>
#include <vector>

#include "src/vector.hpp"

int main() {
  // Arrange
  LinearAlgebra::Vector vector(3);

  // Act
  vector(0) = 2;
  vector(1) = 3;
  vector(2) = -7;

  // Assert
  assert(vector(0) == 2);
  assert(vector(1) == 3);
  assert(vector(2) == -7);

  return 0;
}