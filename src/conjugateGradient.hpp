#ifndef CONJUGATEGRADIENT_HPP
#define CONJUGATEGRADIENT_HPP

#include "src/matrix.hpp"
#include "src/vector.hpp"

namespace LinearAlgebra {

class ConjugateGradient {
public:
  ConjugateGradient() = default;
  void setCoefficientMatrix(const LinearAlgebra::Matrix &matrix);
  void setRHSVector(const LinearAlgebra::Vector &vector);
  LinearAlgebra::Vector solve(const unsigned &maxIterations = 1000, const double &convergenceThreshold = 1e-6);

private:
  double calculateResidual(const unsigned &iteration);

private:
  LinearAlgebra::Matrix coefficientMatrix_;
  LinearAlgebra::Vector solutionVector_;
  LinearAlgebra::Vector rhsVector_;
};

} // namespace LinearAlgebra

#endif