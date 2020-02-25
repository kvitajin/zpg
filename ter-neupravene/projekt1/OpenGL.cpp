#include "OpenGL.h"

OpenGL* OpenGL::instance = NULL;

OpenGL::OpenGL()
{
	this->width = 600;
	this->height = 800;
	window = glfwCreateWindow(this->height, this->width, "ZPG", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glewExperimental = GL_TRUE;
	glewInit();
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
}


OpenGL* OpenGL::getInstance()
{
	if (instance == 0) {
		instance = new OpenGL;
	}
	return instance;
}

OpenGL::~OpenGL()
{
}

void OpenGL::printVersion()
{
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}

int OpenGL::getRatio()
{
	return this->ratio;
}

int OpenGL::getWidth()
{
	return this->width;
}

int OpenGL::getHeight()
{
	return this->height;
}
