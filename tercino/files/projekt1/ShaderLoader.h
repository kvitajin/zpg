#pragma once
//GLEW - The OpenGL Extension Wrangler Library
#include <GL/glew.h>

#include <string.h> 
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class ShaderLoader
{
	GLuint	programID, vertexID, fragmentID;
	GLint status;

	string loadFile(const char* fname);

	void loadVertexShader(const char* vertexShader, int len);
	void loadFragmentShader(const char* fragmentShader, int len);
	void loadProgram();

public:
	ShaderLoader();
	ShaderLoader(const char* vertexFile, const char* fragmentFile, GLuint* shaderID);
	~ShaderLoader();

	GLuint loadShader(const char* vertexFile, const char* fragmentFile);
	void deleteShader();
};
