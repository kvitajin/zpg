//
// Created by kvitajin on 23.10.19.
//

#ifndef CV_VERTEXOBJECT_H
#define CV_VERTEXOBJECT_H

#include <GL/glew.h>
#include <iostream>


class VertexObject {
private:
    GLuint vbo;
    GLuint vao;

public:
    VertexObject(GLuint vao, GLuint vbo);
    ~VertexObject()= default;

    void CreateBufferObject();
    void CreateArrayObject();
    GLuint GetVAO();
    GLuint GetVBO();

};


#endif //CV_VERTEXOBJECT_H
