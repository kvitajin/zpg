//
// Created by kvitajin on 23.10.19.
//

#ifndef CV_VERTEXSHADER_H
#define CV_VERTEXSHADER_H


//Include GLM
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#pragma once
#include "shader.h"

class VertexShader: Shader{
public:
    VertexShader();
    ~VertexShader()= default;

    virtual GLuint GetShader();

};


#endif //CV_VERTEXSHADER_H
