cmake_minimum_required(VERSION 3.19)
project(Client)

set(CMAKE_CXX_STANDARD 14)
set(Headers Client.h)

SET(CMAKE_CXX_FLAGS -pthread)

add_executable(Client main.cpp Client.cpp)