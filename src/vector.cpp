#include "src/vector.hpp"

namespace LinearAlgebra {

Vector::Vector(const Vector::VectorType &inputVector) : vector_(inputVector) { }

void Vector::transpose() {
  isRowVector_ = isRowVector_ == true ? false : true;
}

const double &Vector::operator()(int index) const {
  return vector_[index];
}

Vector &Vector::operator*(const double &scaleFactor) {
  for (auto &vectorComponent : vector_)
    vectorComponent *= scaleFactor;
  return *this;
}

} // namespace LinearAlgebra