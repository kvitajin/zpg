#pragma once

#include"Shader.h"
#include <stdio.h>

class FragmentShader : Shader	
{
public:
	FragmentShader();
	~FragmentShader();

	virtual GLuint GetShader();
};

