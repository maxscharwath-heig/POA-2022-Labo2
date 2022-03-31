SET(CMAKE_CXX_FLAGS --coverage)
add_executable(tests test.cpp catch_main.cpp)