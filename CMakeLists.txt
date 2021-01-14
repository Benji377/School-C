# cmake_minimum_required(VERSION <specify CMake version here>)
project(C_Projects C)

set(CMAKE_C_STANDARD 99)

add_executable(main main.c)
add_executable(rechner rechner.c)
add_executable(vektoren vektoren.c)
add_executable(wurfel wurfel.c)