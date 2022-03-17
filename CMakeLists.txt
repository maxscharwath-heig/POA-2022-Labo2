cmake_minimum_required(VERSION 3.21)
project(POA___Labo_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(POA___Labo_2
        main.cpp
        Squadron.h
        Squadron.cpp
        ship/Ship.h
        ship/Ship.cpp ship/TIE.hpp ship/TIE.cpp ship/TIE.hpp ship/LambdaShuttle.cpp ship/LambdaShuttle.hpp ship/StarDestroyer.cpp ship/StarDestroyer.hpp ship/TIELN.cpp ship/TIELN.hpp ship/TIEIN.cpp ship/TIEIN.hpp)
