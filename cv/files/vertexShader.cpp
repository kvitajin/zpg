//
// Created by kvitajin on 23.10.19.
//

#include <cstdio>
#include "vertexShader.h"

VertexShader::VertexShader(){

// in vertex shader
    this->vertex_shader = "#version 400\n"
                                "layout(location= 0)in vec3 in_Position;"
                                "out vec3 ex_WorldPos;"

                                "uniform mat4 modelMatrix;"
                                "uniform mat4 viewMatrix=mat4(1.0);"
                                "uniform mat4 projectionMatrix=mat4(1.0);"
                                "void main () {"
                                "gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(in_Position, 1.0);"
                                "}";

    this->shader=glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(this->shader, 1, &this->vertex_shader, NULL);
    glCompileShader(this->shader);

    GLint status;
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(this->shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(this->shader, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Compile failure in Vertex shader:\n%s\n", strInfoLog);
        delete[] strInfoLog;
    }

}
GLuint VertexShader::GetShader(){
    return this->shader;
}