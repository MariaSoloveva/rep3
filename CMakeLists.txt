cmake_minimum_required (VERSION 2.8)

include_directories(SYSTEM
    ./
)

ADD_DEFINITIONS(
    -std=c++11
)

# enum your files
add_executable(executable
    REp3.cpp
    checkStudentFailedMl.cpp
    checkStudentPassedAl.cpp
    countGoodStudents.cpp
    countNegligentStudents.cpp
    findAverageScores.cpp
    findMaxOfScores.cpp
    findStudentsgoodAtMath.cpp
)

target_link_libraries(executable)
