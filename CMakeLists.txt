cmake_minimum_required(VERSION 3.22)
project(grayscaler C)

set(CMAKE_C_STANDARD 99)

add_executable(grayscaler main.c stb_image.h stb_writer.h)
