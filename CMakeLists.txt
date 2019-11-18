cmake_minimum_required(VERSION 3.13)
project(testC C)

set(CMAKE_C_STANDARD 99)

add_executable(testC main.c libs/callbacks.c libs/callbacks.h libs/stop_watch.c libs/stop_watch.h libs/utils.c libs/utils.h parser.c parser.h testcode.c testcode.h)