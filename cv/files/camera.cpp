//
// Created by kvitajin on 06.11.19.
//

#include "camera.h"
#include "shader.h"

glm::mat4 Camera::getCamera() {
//    target.x=cos(this->angleHor);
//    target.z=sin(this->angleHor);
//    target.y=sin(this->angleVert);
    return glm::lookAt(eye, eye + target, up);
}

void Camera::toLeft() {
    eye+=(glm::normalize(glm::cross(target,up)));

}
void Camera::toRight() {
    eye-=(glm::normalize(glm::cross(target,up)));
}


Camera::Camera(Shader *shader) {
    this->m_shader=shader;
}

void Camera::toFront() {
    eye+=(glm::normalize(target));
}

void Camera::setShader(Shader *shader) {
    this->m_shader= shader;
}

