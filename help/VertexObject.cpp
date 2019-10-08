#include "VertexObject.h"

VertexObject::VertexObject(GLuint vao, GLuint vbo)
{
	this->VAO = 0;
	this->VBO = 0;
}


VertexObject::~VertexObject()
{
}

void VertexObject::CreateBufferObject()
{
	float p[] = {
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
	};
	glGenBuffers(1, &this->VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(p),p,
		GL_STATIC_DRAW);

}

void VertexObject::CreateArrayObject()
{
	glGenVertexArrays(1, &this->VAO); //generate the VAO
	glBindVertexArray(this->VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER,this->VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

}

GLuint VertexObject::GetVAO()
{
	return this->VAO;
}

GLuint VertexObject::GetVBO()
{
	return this->VBO;
}
