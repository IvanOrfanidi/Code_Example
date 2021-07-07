## Code Example
Проект примеров.

### Сборка с использование CMake
```sh
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```