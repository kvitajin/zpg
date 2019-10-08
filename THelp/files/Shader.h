#pragma once

#include <GL/glew.h>

class Shader
{
protected:
	GLuint shader;
	const char* str_shader;

public:
	Shader();
	virtual ~Shader()=0;

	virtual GLuint GetShader()=0;
};

