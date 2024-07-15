mkdir build
cd build
conan install .. -s build_type=Release --build missing
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
ninja
cd ..