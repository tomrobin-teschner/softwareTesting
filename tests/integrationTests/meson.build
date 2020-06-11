matrixVectorMultiplicationTest = executable(
  'matrixVectorMultiplicationTest',
  'matrixVectorMultiplicationTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('integration test: matrix vector multiplication', matrixVectorMultiplicationTest)

conjugateGradientTest = executable(
  'conjugateGradientTest',
  'conjugateGradientTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('integration test: solve system using conjugate gradient method', conjugateGradientTest)