#pragma once

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glm/glm.hpp"

#include "VertexObject.h"
#include "Shader.h"
#include "Texture.h"
#include "Movement.h"
#include "EnumShaderType.h"

enum ObjectType { Static, Enemy, Background };

class Shader;

class Object
{
protected:
	int id;
	int size;
	int indicesCount = 0;
	GLuint vao;
	ObjectType type;
	ShaderType shaderType;
	Texture* texture;
	Movement* movement = nullptr;
	Vertex* pVertices;

public:
	glm::mat4 modelMatrix = glm::mat4(1.0f);

	Object();
	Object(int id, int size, GLuint vao);
	Object(int id, int size, GLuint vao, ObjectType type);
	Object(int id, int size, GLuint vao, ObjectType type, glm::mat4 modelMatrix);
	Object(int id, int size, GLuint vao, glm::mat4 modelMatrix);
	~Object();

	void setModelMatrixInShader(Shader* shader);
	void setTexture(Texture* texture);
	void setShaderType(ShaderType type);
	void setMovement(glm::vec3 moveVector);
	void setMovement(std::vector<Point*> points);

	void setID(int id);
	int getID();
	int getSize();
	int getIndices();
	GLuint getVao();
	GLuint getTexture();
	ShaderType getShaderType();
	ObjectType getType();
	glm::mat4 getModelMat();

	void move(glm::vec3 translation);
};