#include <cassert>
#include <cmath>

#include "src/conjugateGradient.hpp"
#include "src/matrix.hpp"
#include "src/vector.hpp"

// solve the heat equation implicitly of the form dT/dt = gamma * d^2 T/ dx^2 over a domain L using the conjugate
// gradient methdod
// initial condition: 0 everywhere
// boundary condition: T(0) = 0, T(L) = 1
int main() {
  const double gamma = 1.0;
  const unsigned numberOfCells = 100;
  const double domainLength = 1.0;
  const double boundaryValueLeft = 0.0;
  const double boundaryValueRight = 1.0;
  const double dx = domainLength / (numberOfCells);

  LinearAlgebra::Vector coordinateX(numberOfCells);
  LinearAlgebra::Vector temperature(numberOfCells);
  LinearAlgebra::Vector boundaryConditions(numberOfCells);

  LinearAlgebra::Matrix coefficientMatrix;
  coefficientMatrix.setSize(numberOfCells, numberOfCells);

  // initialise arrays and set-up 1D mesh
  for (unsigned i = 0; i < numberOfCells; ++i) {
    coordinateX(i) = i * dx + dx / 2.0;
    temperature(i) = 0.0;
    boundaryConditions(i) = 0.0;
  }

  // calculate individual matrix coefficients
  const double aE = gamma / dx;
  const double aW = gamma / dx;
  const double aP = aE + aW;
  const double sP = -2.0 * gamma / dx;
  const double sU = 2.0 * gamma / dx;

  // set individual matrix coefficients
  for (unsigned i = 0; i < numberOfCells; ++i)
    coefficientMatrix(i, i) = aP;

  coefficientMatrix(0, 0) += -sP - aW;
  coefficientMatrix(numberOfCells - 1, numberOfCells - 1) += -sP - aE;

  for (unsigned i = 0; i < numberOfCells - 1; ++i) {
    coefficientMatrix(i, i + 1) = -aE;
    coefficientMatrix(i + 1, i) = -aW;
  }

  // set boundary conditions
  boundaryConditions(0) = sU * boundaryValueLeft;
  boundaryConditions(numberOfCells - 1) = sU * boundaryValueRight;

  // solve the linear system using the conjugate gradient method
  LinearAlgebra::ConjugateGradient CGSolver;
  CGSolver.setCoefficientMatrix(coefficientMatrix);
  CGSolver.setRHSVector(boundaryConditions);
  temperature = CGSolver.solve(1000, 1e-10);

  // the obtain temperature profile is a linear one of the form T(x) = x. Thus, we can compare it directly against
  // the coordinate vector (which in this case acts as an analytic solution)
  LinearAlgebra::Vector difference(numberOfCells);
  for (unsigned i = 0; i < numberOfCells; ++i)
    difference(i) += std::fabs(temperature(i) - coordinateX(i));

  // ensure that temperature has converged to at least single precision
  assert(difference.getL2Norm() < 1e-8);

  return 0;
}