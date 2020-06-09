#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>

namespace LinearAlgebra {

class Vector {
public:
  using VectorType = std::vector<double>;

public:
  Vector(const VectorType &inputVector);
  void transpose();

  const double &operator()(int index) const;
  Vector &operator*(const double &scaleFactor);

  friend Vector &operator*(const double &scaleFactor, Vector vector) {
    return vector * scaleFactor;
  }

private:
  VectorType vector_;
  bool isRowVector_ = false;
};

} // namespace LinearAlgebra

#endif