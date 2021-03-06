cmake_minimum_required(VERSION 3.1)

project(testy)

##
### Test definitions ###
##

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(test)

##
### Source definitions ###
##

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/depthOfMarket/*.cpp"
        "${PROJECT_SOURCE_DIR}/depthOfMarket/*.h"
        "${PROJECT_SOURCE_DIR}/perrformanceTools/*.cpp"
        "${PROJECT_SOURCE_DIR}/perrformanceTools/*.h"
        "${PROJECT_SOURCE_DIR}/main.cpp"
        )

add_executable(dom ${sources})