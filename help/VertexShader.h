#pragma once

#include "Shader.h"
#include <stdio.h>

class VertexShader : protected Shader
{
public:
	VertexShader();
	~VertexShader();

	virtual GLuint GetShader();
};

