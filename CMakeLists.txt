cmake_minimum_required(VERSION 3.14)
project(opengl_mandelbrot)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenMP REQUIRED)
find_package(glm REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS})

add_definitions( -DPROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}" )

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR} SOURCES)

add_executable(opengl_mandelbrot ${SOURCES} main.cpp)

target_link_libraries(opengl_mandelbrot glfw)
target_link_libraries(opengl_mandelbrot OpenGL::OpenGL)
target_link_libraries(opengl_mandelbrot ${GLEW_LIBRARIES})
target_link_libraries(opengl_mandelbrot OpenMP::OpenMP_CXX)
