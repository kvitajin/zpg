#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>  

#include <stdlib.h>
#include <stdio.h>

class OpenGL
{
private:
	int major, minor, revision;
	int width, height;
	float ratio;

	static OpenGL* instance;
	OpenGL();
public:
	GLFWwindow* window;

	static OpenGL* getInstance();
	~OpenGL();

	int getWidth();
	int getHeight();
	int getRatio();
	void printVersion();
};

