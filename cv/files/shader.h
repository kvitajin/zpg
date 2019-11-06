//
// Created by kvitajin on 23.10.19.
//
#pragma once
#include <GL/glew.h>
#include <netdb.h>
#include "shader.h"
#include "camera.h"

#ifndef CV_SHADER_H
#define CV_SHADER_H
class Camera;
class Shader{
    Camera* m_camera;
protected:
    const char* vertex_shader;
    const char* fragment_shader;

    GLuint shader;
public:
    Shader(Camera* camera);
    virtual GLuint GetShader()=0;

    Shader();
    virtual ~Shader()= default;
};
#endif //CV_SHADER_H
