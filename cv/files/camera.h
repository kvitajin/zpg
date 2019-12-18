//
// Created by kvitajin on 06.11.19.
//

#ifndef CV_CAMERA_H
#define CV_CAMERA_H
#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include "shader.h"
//-------Camera.h------
class Shader;
class Camera {
    glm::vec3 eye=glm::vec3(10, 0, 0) ;
    glm::vec3 target=glm::vec3((0,0,0));

    glm::vec3 up=glm::vec3(0, 1, 0);

    Shader* m_shader;
    double angleVert=0;
    double angleHor=5;
public:
    Camera(Shader* shader);
    glm::mat4 getCamera();
    void toLeft();
    void toRight();
    void toFront();
    void setShader(Shader* shader);

};


#endif //CV_CAMERA_H
