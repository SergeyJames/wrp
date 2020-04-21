#!/bin/bash
if [ "$#" -ne 3 ]; then
	echo -e "\e[91m[ERROR:$2] Illegal number of parameters!\e[0m"
	exit -1
fi

cd $1/build
export BUILD_TYPE=$2
export WRP_ROOT_ARG=$1

cmake --build . --config $BUILD_TYPE --target install -- -j$3
