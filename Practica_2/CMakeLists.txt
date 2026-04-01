cmake_minimum_required(VERSION 3.16)

project(Practica_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Practica_2 main.cpp
    problem1.cpp
    Problems.h
    problem3.cpp
    problem5.cpp
    problem6.cpp
    problem7.cpp
    problem9.cpp
    problem10.cpp
    problem11.cpp
    problem13.cpp)

include(GNUInstallDirs)
install(TARGETS Practica_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
