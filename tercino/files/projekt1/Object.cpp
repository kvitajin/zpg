#include "Object.h"

Object::Object()
{
}

Object::Object(int id, int size, GLuint vao)
{
	this->id = id;
	this->size = size;
	this->vao = vao;
	this->type = Static;
}

Object::Object(int id, int size, GLuint vao, ObjectType type)
{
	this->id = id;
	this->size = size;
	this->vao = vao;
	this->type = type;
}

Object::Object(int id, int size, GLuint vao, ObjectType type, glm::mat4 modelMatrix)
{
	this->id = id;
	this->size = size;
	this->vao = vao;
	this->modelMatrix = modelMatrix;
	this->type = type;
}

Object::Object(int id, int size, GLuint vao, glm::mat4 modelMatrix)
{
	this->id = id;
	this->size = size;
	this->vao = vao;
	this->modelMatrix = modelMatrix;
	this->type = Static;
}

Object::~Object()
{
}

void Object::setModelMatrixInShader(Shader* shader)
{
	shader->setModelMatrix(this->modelMatrix);
}

void Object::setTexture(Texture* texture)
{
	this->texture = texture;
}

void Object::setShaderType(ShaderType type)
{
	this->shaderType = type;
}

void Object::setMovement(glm::vec3 moveVector)
{
	Point* start = new Point();
	start->x = -2.5;
	start->y = 0.0;
	start->z = 11.5;

	this->movement = new Movement(start, moveVector);
}

void Object::setMovement(std::vector<Point*> points)
{
	this->movement = new Movement(points);
}

void Object::setID(int id)
{
	this->id = id;
}

int Object::getID()
{
	return this->id;
}

int Object::getSize()
{
	return this->size;
}

int Object::getIndices()
{
	return this->indicesCount;
}

GLuint Object::getVao()
{
	return this->vao;
}

ShaderType Object::getShaderType()
{
	return this->shaderType;
}

ObjectType Object::getType()
{
	return this->type;
}

glm::mat4 Object::getModelMat()
{
	if (this->movement == NULL)
	{
		return this->modelMatrix;
	}
	else {
		return glm::translate(this->modelMatrix, this->movement->move());
	}
}

GLuint Object::getTexture()
{
	return this->texture->getTextureId();
}

void Object::move(glm::vec3 translation)
{
	this->modelMatrix = glm::translate(this->modelMatrix, translation);
}
