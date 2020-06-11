#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>

#include "src/matrix.hpp"

namespace LinearAlgebra {

class Vector {
public:
  using VectorType = std::vector<double>;

public:
  Vector() = default;
  Vector(const unsigned &size);
  Vector(const VectorType &inputVector);

  unsigned size() const;
  void resize(const unsigned &size);
  void setValues(const double &value);
  void setConvergenceThresholdForVectorComparison(const double &threshold);

  Vector transpose();
  double getL2Norm() const;

  const double &operator()(int index) const;
  Vector operator+(const Vector &other);
  Vector operator-(const Vector &other);
  Vector &operator*(const double &scaleFactor);
  double operator*(const Vector &other);
  friend Vector &operator*(const double &scaleFactor, Vector vector);
  friend Vector operator*(const Matrix &matrix, const Vector &vector);
  friend std::ostream &operator<<(std::ostream &out, const Vector &vector);
  bool operator==(const Vector &other);

private:
  VectorType vector_;
  bool isRowVector_ = false;
  double comparisonThreshold_ = 1e-4;
};

} // namespace LinearAlgebra

#endif