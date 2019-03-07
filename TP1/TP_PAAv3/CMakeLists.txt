cmake_minimum_required(VERSION 3.10)
project(TP_PAAv3 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP_PAAv3 main.c arq.h arq.c Hash.h Hash.c)