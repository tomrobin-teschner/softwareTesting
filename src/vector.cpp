#include <cassert>

#include "src/vector.hpp"

namespace LinearAlgebra {

Vector::Vector(const Vector::VectorType &inputVector) : vector_(inputVector) { }

void Vector::transpose() {
  isRowVector_ = isRowVector_ == true ? false : true;
}

Vector Vector::operator+(const Vector &other) {
  assert(vector_.size() == other.vector_.size() && "vectors must have the same dimension");
  Vector resultVector;
  resultVector.vector_.resize(vector_.size());
  for (unsigned i = 0; i < vector_.size(); ++i)
    resultVector.vector_[i] = vector_[i] + other.vector_[i];
  return resultVector;
}

Vector Vector::operator-(const Vector &other) {
  assert(vector_.size() == other.vector_.size() && "vectors must have the same dimension");
  Vector resultVector;
  resultVector.vector_.resize(vector_.size());
  for (unsigned i = 0; i < vector_.size(); ++i)
    resultVector.vector_[i] = vector_[i] - other.vector_[i];
  return resultVector;
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