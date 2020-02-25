cmake_minimum_required(VERSION 3.15)
project(tercino)

find_library(glfw3 3.3 REQUIRED)
find_library(glew REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_library(SOIL REQUIRED)
find_library(assimp REQUIRED)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW
        glm
        SOIL
        assimp
        )

set(BUILD_ASSIMP_TOOLS  ON)

set(CMAKE_CXX_STANDARD 14)
add_executable(files
        files/main.cpp
        files/projekt1/Application.cpp
        files/projekt1/Background.cpp
        files/projekt1/Camera.cpp
        files/projekt1/Enemy.cpp
        files/projekt1/FragmentShader.cpp
        files/projekt1/Light.cpp
        files/projekt1/Model.cpp
        files/projekt1/ModelObject.cpp
        files/projekt1/Movement.cpp
        files/projekt1/OpenGL.cpp
        files/projekt1/Object.cpp
        files/projekt1/Renderer.cpp
        files/projekt1/SceneObjects.cpp
        files/projekt1/Shader.cpp
        files/projekt1/ShaderLoader.cpp
        files/projekt1/Source.cpp
        files/projekt1/Texture.cpp
        files/projekt1/VertexObject.cpp)
target_link_libraries( files ${ALL_LIBS})


