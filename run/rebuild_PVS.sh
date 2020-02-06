if [ -d $1/build ]; then
    cd $1/build
    rm -rf *
else
    mkdir $1/build
    cd $1/build
fi

export BUILD_TYPE=$2
export WRP_ROOT_ARG=$1
cmake ../ \
 -DWRP_ROOT=$WRP_ROOT_ARG \
 -DCMAKE_INSTALL_PREFIX=../install \
 -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
 -DCODE_COVERAGE=ON \
 -DCMAKE_CXX_FLAGS_DEBUG="-g -O0 -Wpedantic -Wall -Wextra -Wnarrowing -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option" \
 -DCMAKE_CXX_FLAGS="-fsanitize=address  -fsanitize=leak -g" \
 -DCMAKE_C_FLAGS="-fsanitize=address  -fsanitize=leak -g" \
 -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address  -fsanitize=leak" \
 -DCMAKE_MODULE_LINKER_FLAGS="-fsanitize=address  -fsanitize=leak" \
 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build . --config $BUILD_TYPE  --target install -- -j$3

pvs-studio-analyzer analyze -j$4 -o PVS-Studio.log -e $1/build
plog-converter -t html PVS-Studio.log -o PVS-Studio.html --excludedCodes=V009
