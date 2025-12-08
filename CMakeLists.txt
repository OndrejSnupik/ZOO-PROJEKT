cmake_minimum_required(VERSION 4.0)
project(ZOO_PROJEKT)

set(CMAKE_CXX_STANDARD 14)

add_executable(ZOO_PROJEKT
        main.cpp
        Tile.cpp
        Tile.h
        Hallway.cpp
        Hallway.h
        Map.cpp
        Map.h
)
