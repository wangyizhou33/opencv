cmake_minimum_required(VERSION 3.15)
project(hellow)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(CvPlot)

add_executable(hello hello.cpp)
target_link_libraries(hello ${OpenCV_LIBS})

add_executable(display_image tutorials/display_image.cpp)
target_link_libraries(display_image ${OpenCV_LIBS})

add_executable(basic_drawing tutorials/basic_drawing.cpp)
target_link_libraries(basic_drawing ${OpenCV_LIBS})

add_executable(harris_detector tutorials/harris_detector.cpp)
target_link_libraries(harris_detector ${OpenCV_LIBS})

add_executable(panoroma tutorials/panoroma.cpp)
target_link_libraries(panoroma ${OpenCV_LIBS})

add_executable(distance_transform tutorials/distance_transform.cpp)
target_link_libraries(distance_transform ${OpenCV_LIBS})

add_executable(optical_flow tutorials/optical_flow.cpp)
target_link_libraries(optical_flow ${OpenCV_LIBS})

add_executable(optical_flow_dense tutorials/optical_flow_dense.cpp)
target_link_libraries(optical_flow_dense ${OpenCV_LIBS})

add_executable(image_descriptor tutorials/image_descriptor.cpp)
target_link_libraries(image_descriptor ${OpenCV_LIBS})

add_executable(plot tutorials/plot.cpp)
target_link_libraries(plot ${OpenCV_LIBS})