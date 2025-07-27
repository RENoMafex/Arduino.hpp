# Only edit the marked section below.

cmake_minimum_required(VERSION 3.5)
###################################
# ONLY EDIT THE FOLLOWING SECTION #
###################################
set(PROJECT_NAME myProject)
set(CMAKE_CXX_STANDARD 17)
set(SRC_DIR .)
set(WARNINGS -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2)
###############################
# DO NOT EDIT BELOW THIS LINE #
###############################
add_compile_options(${WARNINGS})
project(${PROJECT_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED true)
file(GLOB SOURCES "${SRC_DIR}/*.c" "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.h" "${SRC_DIR}/*.hpp")
add_executable(${PROJECT_NAME} ${SOURCES})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)