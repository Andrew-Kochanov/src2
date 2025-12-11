cmake_minimum_required(VERSION 3.25)

project(rewrite C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(sortList sortList.c)

add_executable(main main.c)

target_link_libraries(main PRIVATE sortList)
