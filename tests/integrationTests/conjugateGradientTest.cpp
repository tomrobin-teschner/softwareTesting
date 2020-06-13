#include <cassert>
#include <vector>

#include <iostream>

#include "src/conjugateGradient.hpp"
#include "src/matrix.hpp"
#include "src/vector.hpp"

int main() {
  // Arrange
  LinearAlgebra::Matrix A({{2, 1, 0}, {1, 2, 1}, {0, 1, 2}});
  LinearAlgebra::Vector b({3, 1, 5});
  LinearAlgebra::Vector calculatedRHSVector(3);
  LinearAlgebra::ConjugateGradient CGSolver;

  calculatedRHSVector.setConvergenceThresholdForVectorComparison(1e-10);
  CGSolver.setCoefficientMatrix(A);
  CGSolver.setRHSVector(b);

  // Act
  const auto solutionVector = CGSolver.solve();
  calculatedRHSVector = A * solutionVector;

  // Assert
  assert(calculatedRHSVector == b);

  return 0;
}
