cmake_minimum_required(VERSION 3.16)

project(Practica_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Practica_1 main.cpp
    Ejercicios.h
    Ejercicio_1.cpp
    Ejercicio_2.cpp
    Ejercicio_3.cpp
    Ejercicio_4.cpp
    Ejercicio_5.cpp
    Ejercicio_6.cpp
    Ejercicio_7.cpp
)

include(GNUInstallDirs)
install(TARGETS Practica_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
