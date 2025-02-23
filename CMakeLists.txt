cmake_minimum_required(VERSION 3.15)
project(pesudo-stl)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)

add_executable(
    code

    main.cpp
)

target_link_libraries(code PRIVATE ${lib_targets})