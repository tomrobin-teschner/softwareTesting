#include "src/conjugateGradient.hpp"

#include <cmath>

namespace LinearAlgebra {

void ConjugateGradient::setCoefficientMatrix(const LinearAlgebra::Matrix &matrix) {
  coefficientMatrix_ = matrix;
}

void ConjugateGradient::setRHSVector(const LinearAlgebra::Vector &vector) {
  rhsVector_ = vector;
  solutionVector_.resize(rhsVector_.size());
  solutionVector_.setValues(0.0);
}

LinearAlgebra::Vector ConjugateGradient::solve(const unsigned &maxIterations, const double &convergenceThreshold) {
  LinearAlgebra::Vector r0(3), r1(3), d0(3), d1(3);
  auto &A = coefficientMatrix_;
  auto &b = rhsVector_;
  auto &x = solutionVector_;
  double alpha = 0.0;
  double beta = 0.0;
  unsigned iteration = 0;
  double L2Norm = 0.0;
  double previousL2Norm = 0.0;
  double residual = 0.0;

  d1 = b - A * x;
  r1 = b - A * x;

  do {
    r0 = r1;
    d0 = d1;

    alpha = (d0.transpose() * r0) / (d0.transpose() * (A * d0));
    x = x + alpha * d0;
    r1 = r0 - alpha * A * d0;
    beta = (r1.transpose() * r1) / (r0.transpose() * r0);
    d1 = r1 + beta * d0;

    residual = calculateResidual(iteration, x, L2Norm, previousL2Norm);
    ++iteration;
  } while (iteration < maxIterations && residual > convergenceThreshold);

  return solutionVector_;
}

double ConjugateGradient::calculateResidual(
  const unsigned &iteration, const LinearAlgebra::Vector &solution, double &L2Norm, double &previousL2Norm) const {
  static double norm = 0.0;
  previousL2Norm = L2Norm;
  L2Norm = solution.getL2Norm();
  if (iteration == 0)
    norm = L2Norm;
  L2Norm /= norm;
  return std::fabs(L2Norm - previousL2Norm);
}

} // namespace LinearAlgebra