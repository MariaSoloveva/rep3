cmake_minimum_required (VERSION 2.8) 

include_directories(SYSTEM 
./ 
) 

ADD_DEFINITIONS(
    -std=c++11
)

add_executable(executable 
REp3.cpp
) 

target_link_libraries(executable)
