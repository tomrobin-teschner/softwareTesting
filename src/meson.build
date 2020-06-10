# link back to the root directory
root = '../'

# add source files
cppSourceFiles = [
  'vector.cpp',
  'matrix.cpp'
]

# create static library of all cppSourceFiles which allows to easily include them in tests
linear_algebra_lib = shared_library('linearAlgebra', cppSourceFiles, include_directories: root)