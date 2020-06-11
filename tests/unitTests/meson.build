# link back to the root directory
root = '../../'

# vector tests
scalarVectorMultiplicationTest = executable(
  'scalarVectorMultiplicationTest',
  'scalarVectorMultiplicationTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('vector: scalar vector multiplication', scalarVectorMultiplicationTest)

vectorVectorMultiplicationTest = executable(
  'vectorVectorMultiplicationTest',
  'vectorVectorMultiplicationTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('vector: vector vector multiplication', vectorVectorMultiplicationTest)

vectorAdditionTest = executable(
  'vectorAdditionTest',
  'vectorAdditionTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('vector: vector addition', vectorAdditionTest)

vectorSubtractionTest = executable(
  'vectorSubtractionTest',
  'vectorSubtractionTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('vector: vector subtraction', vectorSubtractionTest)

# matrix tests
scalarMatrixMultiplicationTest = executable(
  'scalarMatrixMultiplicationTest',
  'scalarMatrixMultiplicationTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('matrix: scalar matrix multiplication', scalarMatrixMultiplicationTest)

matrixVectorMultiplicationTest = executable(
  'matrixVectorMultiplicationTest',
  'matrixVectorMultiplicationTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('matrix: matrix vector multiplication', matrixVectorMultiplicationTest)

conjugateGradientTest = executable(
  'conjugateGradientTest',
  'conjugateGradientTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('Conjugate Gradient: solve', conjugateGradientTest)