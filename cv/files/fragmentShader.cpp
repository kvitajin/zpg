//
// Created by kvitajin on 23.10.19.
//
#include "fragmentShader.h"

FragmentShader::FragmentShader() {

    this->fragment_shader =
            "#version 330\n"
            "out vec4 frag_colour;"
            "void main () {"
            "     frag_colour = vec4 (0.0, 1.0, 0.53, 1.0);"
            "}";
    this->shader=glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(this->shader, 1, &this->fragment_shader, NULL);
    glCompileShader(this->shader);
}

GLuint FragmentShader::GetShader(){
    return this->shader;
}