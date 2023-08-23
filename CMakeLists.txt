cmake_minimum_required(VERSION 3.25)
project(sortcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(sortcode main.cpp)

add_executable(bubble code/bubble.cc)
add_executable(select code/select.cc)
add_executable(insert code/insert.cc)
add_executable(shell code/shell.cc)
add_executable(merge code/merge.cc)
add_executable(quick code/quick.cc)
add_executable(heap code/heap.cc)
add_executable(counting code/counting.cc)
add_executable(bucket code/bucket.cc)
add_executable(radix code/radix.cc)
