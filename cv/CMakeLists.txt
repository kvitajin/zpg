cmake_minimum_required(VERSION 3.15)
project(cv)

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
add_executable(files files/main.cpp files/vertexShader.cpp files/vertexShader.h files/fragmentShader.cpp files/fragmentShader.h files/shader.cpp files/shader.h files/vertexObject.cpp files/vertexObject.h files/camera.cpp files/camera.h files/ShaderLoader.cpp )
target_link_libraries( files ${ALL_LIBS})


