cmake_minimum_required(VERSION 3.27)
project(snake)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(snake
        board.cpp
        board.h
        controller.cpp
        controller.h
        snake.cpp
        snake.h
        ui.cpp
        ui.h)
