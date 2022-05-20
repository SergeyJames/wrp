#!/bin/bash

if [ "$#" -ne 4 ]; then
	echo -e "\e[91m[ERROR: $0] Illegal number of parameters!\e[0m"
	exit -1
fi

export BUILD_TYPE=$2
export WRP_ROOT_ARG=$1

if [ $4 == "rebuild" ]; then

	if [ -d $1/build ]; then
		cd $1/build
		rm -rf *
	else
		mkdir $1/build
		cd $1/build
	fi

	cmake ../ \
	 -DWRP_ROOT=$WRP_ROOT_ARG \
	 -DCMAKE_INSTALL_PREFIX=../install \
	 -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
	 -DCMAKE_CXX_FLAGS_DEBUG="-g -O0 -Wpedantic -Wall -Wextra -Wnarrowing -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option" \
	 -DCMAKE_CXX_FLAGS="-fsanitize=address  -fsanitize=leak -g" \
	 -DCMAKE_C_FLAGS="-fsanitize=address  -fsanitize=leak -g" \
	 -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address  -fsanitize=leak" \
	 -DCMAKE_MODULE_LINKER_FLAGS="-fsanitize=address  -fsanitize=leak"

else
	echo -e "\e[42m[Resuming] $2!\e[0m"
	cd $1/build
fi


cmake --build . --config $BUILD_TYPE -- -j$3
cmake --build . --target install  

