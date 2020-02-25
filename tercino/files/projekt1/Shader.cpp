#include "Shader.h"

Shader::Shader()
{
	this->modelMatrix = glm::mat4(1.0f);
	this->viewMatrix = Camera::GetInstance()->GetViewMatrix();
	this->projectionMatrix = Camera::GetInstance()->GetProjectionMatrix();
}

Shader::~Shader()
{
}

void Shader::useProgram(GLuint id, ShaderType type)
{
	this->shader = id;
	this->type = type;

	this->setModelMatrix();
	this->setViewMatrix();
	this->setProjectionMatrix();
	this->setNormalMatrix();
	this->setLight();

	if (type == AssimpShader || type == TextureShader) {
		GLint isNormalTextureID = glGetUniformLocation(this->shader, "isNormalTexure");
		glUniform1i(isNormalTextureID, 0);
		this->setTexture();
	}
}

void Shader::cameraIsMoved(Camera* camera)
{
	this->projectionMatrix = camera->GetProjectionMatrix();
	this->viewMatrix = camera->GetViewMatrix();
}

void Shader::setModelMatrix()
{
	GLuint modelMatrixID = glGetUniformLocation(this->shader, "modelMatrix");
	glUseProgram(this->shader);
	glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, glm::value_ptr(this->modelMatrix));
}

void Shader::setViewMatrix()
{
	GLuint viewMatrixID = glGetUniformLocation(this->shader, "viewMatrix");
	glUseProgram(this->shader);
	glUniformMatrix4fv(viewMatrixID, 1, GL_FALSE, glm::value_ptr(this->viewMatrix));
}

void Shader::setProjectionMatrix()
{
	GLuint projectionMatrixID = glGetUniformLocation(this->shader, "projectionMatrix");
	glUseProgram(this->shader);
	glUniformMatrix4fv(projectionMatrixID, 1, GL_FALSE, glm::value_ptr(this->projectionMatrix));
}

void Shader::setNormalMatrix()
{
	this->normalMatrix = glm::transpose(glm::inverse(glm::mat3(this->modelMatrix)));
	GLuint normalMatrixID = glGetUniformLocation(this->shader, "normalMatrix");
	glUseProgram(this->shader);
	glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, glm::value_ptr(this->normalMatrix));
}

void Shader::setModelMatrix(glm::mat4 m)
{
	this->modelMatrix = m;
}

void Shader::setLight()
{
	glm::vec3 light = lights[0]->getPosition();
	GLint myLoc = glGetUniformLocation(this->shader, "lightPosition");
	glProgramUniform3f(this->shader, myLoc, light.x, light.y, light.z);

	GLint countID = glGetUniformLocation(this->shader, "numberOflights");
	glUniform1i(countID, this->lights.size());
	for (int i = 0; i < this->lights.size(); i++) {
		light = lights[i]->getPosition();
		myLoc = glGetUniformLocation(this->shader, "lights[" + i + ']');
		glUniform3f(myLoc, light.x, light.y, light.z);
	}
}

void Shader::setTexture()
{
	GLint uniformID = glGetUniformLocation(this->shader, "textureUnitID");
	glUniform1i(uniformID, 0);
}

void Shader::addLight(Light* l)
{
	this->lights.push_back(l);
}

void Shader::removeLight(Light* l)
{
	//std::vector<Light*>::iterator it = std::find(lights.begin(), lights.end(), l);
	//this->lights.erase(it);
}

void Shader::setNormalTexture()
{
	GLint isNormalTextureID = glGetUniformLocation(this->shader, "isNormalTexure");
	glUniform1i(isNormalTextureID, 1);
	GLint uniformID = glGetUniformLocation(this->shader, "normalTexture");
	glUniform1i(uniformID, 0);
}
