cmake_minimum_required (VERSION 2.8)

include_directories(SYSTEM
    ./
)

ADD_DEFINITIONS(
    -std=c++11
)

# enum your files
add_executable(executable
    l.cpp
    checkStudentFailedMl.cpp
    checkStudentPassedAl.cpp
    countGoodStudents.cpp
    countNegligentStudents.cpp
    findAverageScores.cpp
    findMaxOfScores.cpp
)

target_link_libraries(executable)
