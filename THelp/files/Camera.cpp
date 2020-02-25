//
// Created by kvitajin on 09.10.19.
//

#include "Camera.h"

glm::mat4 Camera::getCamera(void){
    glm::vec3 eye=glm::vec3(1.0);
    glm::vec3 target;
    glm::vec3 up=glm::vec3(1.0);
    int fi=0;
    int psi=0;

    target.x=cos(fi);
    target.z=sin(fi);
    target.y=sin(psi);


    return glm::lookAt(eye, eye+target, up);
}


