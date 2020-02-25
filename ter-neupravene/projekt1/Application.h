#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <Windows.h>

#include "OpenGL.h"
#include "VertexObject.h"
#include "Object.h"
#include "Camera.h"
#include "ShaderLoader.h"
#include "Model.h"
#include "Texture.h"
#include "Renderer.h"
#include "SceneObjects.h"


class Application
{
private:

	glm::mat4 M = glm::mat4(1.0f);
	int autoId = 1;
	Renderer* renderer;

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);

	void run();
	void removeObjectOnClick();
	void loadRender();
	void setBackground();
	void loadObjects();

	static Application* instance;
	Application();

public:
	static Application* GetInstance();
	~Application();
};

