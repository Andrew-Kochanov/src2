cmake_minimum_required(VERSION 3.25)

project(advancBalancStap C)

add_library(stack stack.c)

add_executable(advancBalancStap advancBalancStap.c)

target_link_libraries(advancBalancStap PRIVATE stack)