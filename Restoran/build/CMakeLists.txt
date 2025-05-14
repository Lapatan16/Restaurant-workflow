cmake_minimum_required(VERSION 3.22)
project(Restoran)

set(CMAKE_CXX_STANDARD 23)
set(SRC_FILES
    ../main/Main.cpp
    ../jelo/Sastojak.cpp
    ../jelo/Jelo.cpp
    ../jelo/Jelovnik.cpp
    ../restoran/Generator.cpp
    ../restoran/Restoran.cpp
    ../restoran/Sto.cpp
    ../osoba/Osoba.cpp
    ../osoba/Musterija.cpp
    ../osoba/Konobar.cpp
)

add_executable(exe ${SRC_FILES})