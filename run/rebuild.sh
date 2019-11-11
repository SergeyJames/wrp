if [ -d $1/build ]; then
    cd $1/build
    rm -rf *
else
    mkdir $1/build
    cd $1/build
fi

export BUILD_TYPE=$2
export WRP_ROOT_ARG=$1
cmake .. \
 -DWRP_ROOT=$WRP_ROOT_ARG \
 -DCMAKE_INSTALL_PREFIX=../install \
 -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
 -DCODE_COVERAGE=ON


cmake --build . --config $BUILD_TYPE -- -j$3
cmake --build . --target install  

