//
// Created by kvitajin on 23.10.19.
//

#include "vertexObject.h"

VertexObject::VertexObject(GLuint vao, GLuint vbo){
    this->vao=vao;
    this->vbo=vbo;
}

void VertexObject::CreateBufferObject() {
    //vertex buffer object (VBO)

    float points[] = {
            0.0f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f
    };
    glGenBuffers(1, &this->vbo); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof (points), points,
                 GL_STATIC_DRAW);
}

void VertexObject::CreateArrayObject() {
    //vertex attribute object(VAO)
    glGenVertexArrays(1, &this->vao); //generate the VAO
    glBindVertexArray(this->vao); //bind the VAO
    glEnableVertexAttribArray(0); //enable vertex attributes
    glBindBuffer(GL_ARRAY_BUFFER,this->vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

GLuint VertexObject::GetVAO() {
    return this->vao;
}
GLuint VertexObject::GetVBO() {
    return  this->vbo;
}







