#include <cassert>
#include <cmath>

#include <iostream>

#include "src/matrix.hpp"
#include "src/vector.hpp"

namespace LinearAlgebra {

Vector::Vector(const Vector::VectorType &inputVector) : vector_(inputVector) { }
Vector::Vector(const unsigned &size) {
  vector_.resize(size);
  for (auto &entry : vector_)
    entry = 0.0;
}

unsigned Vector::size() const {
  return vector_.size();
}
void Vector::resize(const unsigned &size) {
  vector_.resize(size);
}

void Vector::setValues(const double &values) {
  for (auto &entry : vector_)
    entry = values;
}

void Vector::setConvergenceThresholdForVectorComparison(const double &threshold) {
  comparisonThreshold_ = threshold;
}

Vector Vector::transpose() {
  Vector transposedVector;
  transposedVector.vector_ = vector_;
  transposedVector.isRowVector_ = isRowVector_ == true ? false : true;
  return transposedVector;
}

double Vector::getL2Norm() const {
  double L2Norm = 0.0;
  for (const auto &entry : vector_)
    L2Norm += std::pow(entry, 2);
  L2Norm = std::sqrt(L2Norm);
  return L2Norm;
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

double &Vector::operator()(int index) {
  return vector_[index];
}

const double &Vector::operator()(int index) const {
  return vector_[index];
}

Vector &Vector::operator*(const double &scaleFactor) {
  for (auto &vectorComponent : vector_)
    vectorComponent *= scaleFactor;
  return *this;
}

double Vector::operator*(const Vector &other) {
  assert(isRowVector_ && !other.isRowVector_ && "first vector must be a row vector, second must be a column vector");
  double sum = 0.0;
  for (unsigned i = 0; i < vector_.size(); ++i)
    sum += vector_[i] * other.vector_[i];
  return sum;
}

Vector &operator*(const double &scaleFactor, Vector vector) {
  return vector * scaleFactor;
}

Vector operator*(const Matrix &matrix, const Vector &vector) {
  assert(matrix.getNumberOfRows() == vector.vector_.size() && !vector.isRowVector_ &&
    "matrix's row must be equal to entries in column vector");
  Vector resultVector;
  resultVector.vector_.resize(vector.vector_.size());

  for (unsigned row = 0; row < matrix.getNumberOfRows(); ++row)
    for (unsigned col = 0; col < matrix.getNumberOfColumns(); ++col)
      resultVector.vector_[row] += matrix(row, col) * vector.vector_[col];

  return resultVector;
}

std::ostream &operator<<(std::ostream &out, const Vector &vector) {
  out << "( ";
  for (const auto &entry : vector.vector_)
    out << entry << " ";
  out << ")";
  return out;
}

bool Vector::operator==(const Vector &other) {
  assert(vector_.size() > 0 && "vector does not have any entries");
  if (vector_.size() != other.vector_.size())
    return false;

  for (unsigned col = 0; col < vector_.size(); ++col) {
    const double difference = std::fabs(vector_[col] - other.vector_[col]);
    if (difference > comparisonThreshold_)
      return false;
  }
  return true;
}

} // namespace LinearAlgebra