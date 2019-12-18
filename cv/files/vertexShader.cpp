//
// Created by kvitajin on 23.10.19.
//

#include <cstdio>
#include "vertexShader.h"

VertexShader::VertexShader(){

// in vertex shader
    //glm::mat4 projection=glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    this->vertex_shader = "#version 400\n"
                                "layout(location= 0)in vec3 in_Position;"
                                "out vec3 ex_WorldPos;"

                                "uniform mat4 modelMatrix;"
                                "uniform mat4 viewMatrix;"
                                "uniform mat4 projectionMatrix;"
                                "void main () {"
                                "gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(in_Position, 1.0);"
                                "}";

    this->shader=glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(this->shader, 1, &this->vertex_shader, nullptr);
    glCompileShader(this->shader);

    GLint status;
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(this->shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        auto *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(this->shader, infoLogLength, nullptr, strInfoLog);
        fprintf(stderr, "Compile failure in Vertex shader:\n%s\n", strInfoLog);
        delete[] strInfoLog;
    }

}
GLuint VertexShader::GetShader(){
    return this->shader;
}