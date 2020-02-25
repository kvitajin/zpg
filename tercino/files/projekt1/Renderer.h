#pragma once

#include <GL/glew.h>

#include "SceneObjects.h"
#include "Shader.h"

class Renderer
{
private:
	Shader* shader;

	bool IsDrawable();

public:
	GLuint shaderPhong = -1;
	GLuint shaderTexture = -1;
	GLuint shaderAssimp = -1;

	Renderer(Shader* shader);
	~Renderer();

	void draw();
};

