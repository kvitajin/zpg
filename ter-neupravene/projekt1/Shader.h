#pragma once

#include <GL/glew.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/gtx/string_cast.hpp>

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

#include "Camera.h"
#include "Light.h"
#include "EnumShaderType.h"

class Camera;

class Shader
{
private:
	GLuint shader;
	GLuint vertexShader;
	GLuint fragmentShader;

	glm::mat4 modelMatrix;
	glm::mat4 identityMatrix = glm::mat4(1.0f);
	glm::mat3 normalMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	std::vector<Light*> lights;
	ShaderType type;

public:
	Shader();
	~Shader();

	void cameraIsMoved(Camera* camera);
	void useProgram(GLuint id, ShaderType type);

	void setModelMatrix(glm::mat4);
	void addLight(Light* l);
	void removeLight(Light* l);
	void setNormalTexture();

private:
	void setModelMatrix();
	void setViewMatrix();
	void setProjectionMatrix();
	void setNormalMatrix();
	void setLight();
	void setTexture();
};

