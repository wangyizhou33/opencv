cmake_minimum_required(VERSION 3.15)
project(hellow)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(hello hello.cpp)
target_link_libraries(hello ${OpenCV_LIBS})