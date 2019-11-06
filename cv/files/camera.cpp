//
// Created by kvitajin on 06.11.19.
//

#include "camera.h"
#include "shader.h"

glm::mat4 Camera::getCamera() {
    target.x=cos(fi);
    target.z=sin(fi);
    target.y=sin(psi);
    return glm::lookAt(eye, eye + target, up);
}

void Camera::toLeft() {
    eye-=(glm::normalize(glm::cross(target,up)));

}
void Camera::toRight() {
    eye+=(glm::normalize(glm::cross(target,up)));
}


Camera::Camera(Shader *shader) {
    this->m_shader=shader;
}

void Camera::toFront() {


}
