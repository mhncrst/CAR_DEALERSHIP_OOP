cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        ciorna.cpp
        Masina.cpp
        DEALERSHIP.h
        SEDAN.h
        CABRIO.h
        SUV.h
        SUV.cpp
        SEDAN.cpp
        CABRIO.cpp
)
