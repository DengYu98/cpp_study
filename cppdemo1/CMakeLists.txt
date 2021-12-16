cmake_minimum_required(VERSION 3.19)
project(cppdemo1)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-fno-elide-constructors)
add_executable(cppdemo1  Test.cpp structTest.cpp)
add_executable(cppdemo2 main.cpp)
add_executable(cppdemo3 structTest.cpp)
add_executable(cppdemo4 BigMemoryPool.cpp)