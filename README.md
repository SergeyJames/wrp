## How to build bash
```
$ mkdir build install
$ cd build
$ export BUILD_TYPE=RELEASE
$ cmake .. \
 -DWRP_ROOT=<path_to_root> \
 -DCMAKE_INSTALL_PREFIX=../install \
 -DCMAKE_BUILD_TYPE=$BUILD_TYPE

 $ cmake --build . --config $BUILD_TYPE -- -j24
```
 * Note: ***BUILD_TYPE=DEBUG*** or ***BUILD_TYPE=RELEASE***

## Running the tests

