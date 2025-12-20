cmake_minimum_required(VERSION 3.25)

project(sortStation C)

add_library(stack stack.c)

add_executable(sortStation sortStation.c)

target_link_libraries(sortStation PRIVATE stack)
