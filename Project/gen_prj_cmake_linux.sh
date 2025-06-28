cmake -B ../Build/Linux_CMake -DSYSTEM_TARGET=Linux -G "Ninja Multi-Config" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cmake --build ../Build/Linux_CMake --config $1