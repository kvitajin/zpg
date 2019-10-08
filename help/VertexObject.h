#pragma once

#include <GL/glew.h>
#include <stdio.h>

#include <iostream>

using namespace std;

class VertexObject
{
private:
	GLuint VBO;
	GLuint VAO;

public:
	VertexObject(GLuint vao, GLuint vbo);
	~VertexObject();

	void CreateBufferObject();
	void CreateArrayObject();
	GLuint GetVAO();
	GLuint GetVBO();
};

