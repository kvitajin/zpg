cmake_minimum_required(VERSION 3.14)
project(THelp)

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
add_executable(files files/FragmentShader.cpp files/OpenGL.cpp files/Shader.cpp files/Source.cpp files/VertexObject.cpp files/VertexShader.cpp files/Camera.cpp files/Camera.h)
target_link_libraries( files ${ALL_LIBS})
