//
// Created by kvitajin on 23.10.19.
//

#ifndef CV_FRAGMENTSHADER_H
#define CV_FRAGMENTSHADER_H

#include "shader.h"


class FragmentShader:Shader{
public:
    FragmentShader();
    ~FragmentShader()= default;

    virtual GLuint GetShader();
};





#endif //CV_FRAGMENTSHADER_H
