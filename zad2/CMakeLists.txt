cmake_minimum_required(VERSION 3.4)
project(zad2 C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(wrfifo wrfifo.c)
add_executable(rdfifo rdfifo.c)