cd $1/build
export BUILD_TYPE=$2
export WRP_ROOT_ARG=$1

cmake --build . --config $BUILD_TYPE -- -j$3
cmake --build . --target install  

