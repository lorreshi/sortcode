cmake_minimum_required(VERSION 3.25)
project(sortcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(sortcode main.cpp)

add_executable(bubble code/bubble.cc)

add_executable(select code/select.cc)

add_executable(insert code/insert.cc)