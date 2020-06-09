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

vectorAdditionTest = executable(
  'vectorAdditionTest',
  'vectorAdditionTest.cpp',
  link_with: linear_algebra_lib,
  include_directories: root
)
test('vector: vector addition', vectorAdditionTest)