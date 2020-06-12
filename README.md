[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.3891942.svg)](https://doi.org/10.5281/zenodo.3891942)

# Introduction

This project is intended as an example project highlighting a possible folder structure to set up unit, integration and system tests. For this demonstration, a simplistic linear algebra package is developed which consists of a vector and matrix class. From these two classes, a conjugate gradient class is created to solve a linear system of equations. To demonstrate the usage, a system test is provided for the solution of a 1D heat equation, solved implicitly.

# Usage

In order to run this code, [meson](https://mesonbuild.com/), [ninja](https://ninja-build.org/) and [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) need to be installed ([LCOV](http://ltp.sourceforge.net/coverage/lcov.php) only if test coverage reports should be produced). To configure the project, run

```
meson build
```
followed by
```
ninja -C build test
```
This will run all tests in the test suite. To generate test coverage reports as an html file, run
```
ninja -C build coverage
```
which will generate the output within the ```build``` folder.

# Disclaimer

This piece of software is intended as a guide for setting up a test structure comprising of unit, integration and system tests using the meson build system. As such, the developed code is written for educational purposes only and no attempt has been made to optimise the code. You may use it in any way you wish according to the LICENSE but no warrenty is provided for the correctness of the software (which is an oxymoron, I know, as this project is all about testing and ensuring its correctness. It needs to be stated, however).
