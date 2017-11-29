cmake_minimum_required (VERSION 2.8)

include_directories(SYSTEM
    ./
)

ADD_DEFINITIONS(
    -std=c++11
)

# enum your files
add_executable(executable
    lab09.cpp
    10ones.cpp
    11mult.cpp
    12equal.cpp
    1stringCopy.cpp
    2stringConcatinate.cpp
    3newMatrix.cpp
    4deleteMatrix.cpp
    5snake.cpp
    6copy.cpp
    7transpose.cpp
    8inverse.cpp
    9determinant.cpp
)

target_link_libraries(executable)
