cmake_minimum_required(VERSION 3.10)
project(TP1_PAAv1 C)

set(CMAKE_C_STANDARD 99)

add_library(TP1_PAAv1 main.c arq.c arq.h Hash.c Hash.h)