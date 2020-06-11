#include <cassert>
#include <vector>

#include "src/conjugateGradient.hpp"
#include "src/matrix.hpp"
#include "src/vector.hpp"

int main() {
  // Arrange
  LinearAlgebra::Matrix A({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  LinearAlgebra::Vector b({20, 50, 80});
  LinearAlgebra::Vector calculatedRHSVector(3);
  LinearAlgebra::ConjugateGradient CGSolver;
  calculatedRHSVector.setConvergenceThresholdForVectorComparison(1e-10);
  CGSolver.setCoefficientMatrix(A);
  CGSolver.setRHSVector(b);

  // Act
  const auto solutionVector = CGSolver.solve(100, 1e-12);
  calculatedRHSVector = A * solutionVector;

  // Assert
  assert(calculatedRHSVector == b);

  return 0;
}