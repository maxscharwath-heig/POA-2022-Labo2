cmake_minimum_required(VERSION 3.21)
project(POA_Labo_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(POA_Labo_2
        main.cpp
        Squadron.hpp Squadron.cpp
        ship/Ship.hpp ship/Ship.cpp
        ship/LambdaShuttle.cpp ship/LambdaShuttle.hpp
        ship/StarDestroyer.cpp ship/StarDestroyer.hpp
        ship/TIELN.cpp ship/TIELN.hpp
        ship/TIEIN.cpp ship/TIEIN.hpp
        ship/LoadedShip.cpp ship/LoadedShip.hpp
        utility/Utils.hpp
        Constants.hpp
        )

add_subdirectory(tests)