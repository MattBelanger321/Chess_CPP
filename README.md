# C++ CHESS APPLICATION

## DEPENDENCIES
-	Conan version 1.x.x
-	CMake
-	Ninja

## Build Instructions

1. 	Clone repo
2. `mkdir build`
3. `cd build`
4. `conan instal .. -s build_type=Release --build missing`
5. configure CMake
6. `ninja`

```bat
git clone https://github.com/MattBelanger321/Chess_CPP
cd Chess_CPP
mkdir build
cd build
conan install .. -s build_type=Release --build missing
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
ninja
cd ..
```
