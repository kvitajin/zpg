//
// Created by kvitajin on 23.10.19.
//

#include "shader.h"


Shader::Shader(){
    this->vertex_shader=nullptr;
    this->fragment_shader= nullptr;

}

Shader::Shader(Camera *camera) {
    this->m_camera=camera;
}
