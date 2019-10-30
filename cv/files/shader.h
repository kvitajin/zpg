//
// Created by kvitajin on 23.10.19.
//

#include <GL/glew.h>
#include <netdb.h>

#ifndef CV_SHADER_H
#define CV_SHADER_H

#endif //CV_SHADER_H
class Shader{
protected:
    const char* vertex_shader;
    const char* fragment_shader;

    GLuint shader;
public:
    virtual GLuint GetShader()=0;

    Shader();
};