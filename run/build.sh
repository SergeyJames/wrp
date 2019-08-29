cd $1
mkdir build install
cd build
rm -rf *

export BUILD_TYPE=$2
export WRP_ROOT_ARG=$1
cmake .. \
 -DWRP_ROOT=$WRP_ROOT_ARG \
 -DCMAKE_INSTALL_PREFIX=../install \
 -DCMAKE_BUILD_TYPE=$BUILD_TYPE


cmake --build . --config $BUILD_TYPE -- -j24
cmake --build . --target install  


