#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>

namespace LinearAlgebra {

class Vector {
public:
  using VectorType = std::vector<double>;

public:
  Vector() = default;
  Vector(const VectorType &inputVector);

  Vector &transpose();

  const double &operator()(int index) const;
  Vector operator+(const Vector &other);
  Vector operator-(const Vector &other);
  Vector &operator*(const double &scaleFactor);
  double operator*(const Vector &other);
  friend Vector &operator*(const double &scaleFactor, Vector vector);

private:
  VectorType vector_;
  bool isRowVector_ = false;
};

} // namespace LinearAlgebra

#endif