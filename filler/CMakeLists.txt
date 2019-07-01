cmake_minimum_required(VERSION 3.14)
project(filler C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(filler
        distance.c
        filler.c
        filler.h
        save_data.c)
