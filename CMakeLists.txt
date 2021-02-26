cmake_minimum_required(VERSION 3.17)
project(datetime C)

set(CMAKE_C_STANDARD 99)

add_executable(datetime main.c datetime.c datetime.h)