cmake_minimum_required(VERSION 3.14)
project(pokus2)

find_library(glfw3 3.3 REQUIRED)
find_library(glew REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW
        glm
        )

set(CMAKE_CXX_STANDARD 14)
add_executable(file file/main.cpp)
target_link_libraries( file ${ALL_LIBS})