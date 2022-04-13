SET(CMAKE_CXX_FLAGS --coverage)
add_executable(tests test.cpp
        ../Squadron.hpp ../Squadron.cpp
        ../ship/Ship.hpp ../ship/Ship.cpp
        ../ship/LambdaShuttle.cpp ../ship/LambdaShuttle.hpp
        ../ship/StarDestroyer.cpp ../ship/StarDestroyer.hpp
        ../ship/TIELN.cpp ../ship/TIELN.hpp
        ../ship/TIEIN.cpp ../ship/TIEIN.hpp
        ../ship/LoadedShip.cpp ../ship/LoadedShip.hpp
        ../Constants.hpp
        )