//
// Created by kvitajin on 23.10.19.
//

#include "vertexShader.h"

VertexShader::VertexShader(){

// in vertex shader
    this->vertex_shader = "#version 330\n"
                                "uniform mat4 modelMatrix;"
                                "layout(location=0) in vec3 vp;"
                                "void main () {"
                                " gl_Position = modelMatrix * vec4 (vp, 1.0);"
                                "}";
    this->shader=glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(this->shader, 1, &this->vertex_shader, NULL);
    glCompileShader(this->shader);


}
GLuint VertexShader::GetShader(){
    return this->shader;
}


