cmake_minimum_required(VERSION 3.10)
project(exfil CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_executable(exfil src/main.cpp src/server.cpp src/client.cpp)

