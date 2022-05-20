## gitlab   [![Build Status](https://gitlab.com/SergeyJames/wrp/badges/master/pipeline.svg)](https://gitlab.com/SergeyJames/wrp/)

## How to build bash v.1
```
$ git clone --recursive https://github.com/SergeyJames/wrp.git
$ cd wrp/
$ ./run/build.sh . Release
$ ./build/bin/unit_tests
```

## How to build bash v.2
```
$ git clone --recursive https://github.com/SergeyJames/wrp.git
$ cd wrp/
$ mkdir build install
$ cd build
$ export BUILD_TYPE=RELEASE
$ cmake .. \
 -DWRP_ROOT=<path_to_root> \
 -DCMAKE_INSTALL_PREFIX=../install \
 -DCMAKE_BUILD_TYPE=$BUILD_TYPE

 $ cmake --build . --config $BUILD_TYPE -- -j24
 $ cmake --build . --target install
```
 * Note: ***BUILD_TYPE=DEBUG*** or ***BUILD_TYPE=RELEASE***

## Running the tests

```
$ ./bin/unit_tests
```
```
[==========] Running 3 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 2 tests from Algorithms
[ RUN      ] Algorithms.contains
[       OK ] Algorithms.contains (0 ms)
[ RUN      ] Algorithms.contains_if
[       OK ] Algorithms.contains_if (0 ms)
[----------] 2 tests from Algorithms (0 ms total)

[----------] 1 test from Utilities
[ RUN      ] Utilities.isFirstDerivedOfSecond
[       OK ] Utilities.isFirstDerivedOfSecond (0 ms)
[----------] 1 test from Utilities (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 3 tests.
```
