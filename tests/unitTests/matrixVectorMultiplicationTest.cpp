#include <cassert>
#include <vector>

#include "src/matrix.hpp"
#include "src/vector.hpp"

int main() {
  // Arrange
  LinearAlgebra::Matrix matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  LinearAlgebra::Vector vector({6, -2, 6});

  // Act
  const auto resultvector = matrix * vector;

  // Assert
  assert(resultvector(0) == 20);
  assert(resultvector(1) == 50);
  assert(resultvector(2) == 80);

  return 0;
}