//
// Created by kvitajin on 23.10.19.
//

#include "vertexObject.h"
#include "koule/sphere.h"

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
    glBufferData(GL_ARRAY_BUFFER, sizeof (sphere), sphere,
                 GL_STATIC_DRAW);
}

void VertexObject::CreateArrayObject() {
    //vertex attribute object(VAO)
//    glGenVertexArrays(1, &this->vao); //generate the VAO
//    glBindVertexArray(this->vao); //bind the VAO
//    glEnableVertexAttribArray(0); //enable vertex attributes
//    glBindBuffer(GL_ARRAY_BUFFER,this->vao);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    GLuint vbo = 0;
    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sphere), sphere, GL_STATIC_DRAW);


    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(GLvoid*)0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(GLvoid*)(3*sizeof(float)));
//([float, float, float], [float, float, float]) 3xfloat position, 3xfloat normal

/*
void glVertexAttribPointer(
   GLuint index,  //index of the generic vertex attribute to be modified.
   GLint size,    //number of components per generic vertex attribute.
   GLenum type,   //data type of each component in the array.
   GLboolean normalized, //specifies whether fixed-point data values should be normalized.
   GLsizei stride,       //byte offset between consecutive generic vertex attributes.
   const GLvoid * pointer);  //offset of the first component of the first generic vertex attribute in the array in the data store.
*/

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(GLvoid*)0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(GLvoid*)(3*sizeof(float)));
//([float, float, float], [float, float, float]) 3xfloat position, 3xfloat normal











}

GLuint VertexObject::GetVAO() {
    return this->vao;
}
GLuint VertexObject::GetVBO() {
    return  this->vbo;
}







