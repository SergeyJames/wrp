## How to build
mkdir build install
cd build
export BUILD_TYPE=Release
cmake .. \
 -DWRP_ROOT=<path_to_root> \
 -DCMAKE_INSTALL_PREFIX=../install \
 -DCMAKE_BUILD_TYPE=$BUILD_TYPE
```

## Running the tests

