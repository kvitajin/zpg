#pragma once

#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <stdio.h>

#include "VertexStruct.h"

class VertexObject
{
private:
	GLuint vbo;
	GLuint vao;
	GLuint ibo;

public:
	VertexObject();
	~VertexObject();

	GLuint getVao();

	void loadBall();
	void loadPlainTexture();
	void loadModelTexture(unsigned int numVertices, unsigned int numFaces, unsigned int* pIndices, Vertex* pVertices);
};

