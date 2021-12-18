cmake_minimum_required(VERSION 3.19)
project(linguagem C)

set(CMAKE_C_STANDARD 99)

add_executable(linguagem main.c language.h language.c main.c language.c runner.h runner.c)