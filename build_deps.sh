#! /bin/sh
ROOT_DIR=$(pwd)
cd vendor/glfw &&\
cmake -S . -B build\
  -DGLFW_BUILD_DOCS=OFF\
  -DGLFW_BUILD_TESTS=OFF\
  -DGLFW_BUILD_EXAMPLES=OFF\
  -DBUILD_SHARED_LIBS=OFF &&\
cmake --build build --parallel$(nproc) &&\
cp build/src/libglfw3.a "${ROOT_DIR}/deps/"
