
//Include GLEW
#include <GL/glew.h>

//Include GLFW
// C:\Users\Tess\Downloads\Libraries\glfw\lib-vc2015 zachováno
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

#include "OpenGL.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "VertexObject.h"

float points[9] = {
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};

static void error_callback(int error, const char* description) { fputs(description, stderr); }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

static void window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

static void window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

static void window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

static void cursor_callback(GLFWwindow *window, double x, double y) { printf("cursor_callback \n"); }

static void button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

//GLM test

// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);

// Camera matrix
glm::mat4 View = glm::lookAt(
	glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
	glm::vec3(0, 0, 0), // and looks at the origin
	glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
);
// Model matrix : an identity matrix (model will be at the origin)
glm::mat4 Model = glm::mat4(1.0f);

glm::mat4 M = glm::mat4(1.0f);

int main(void)
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}
	
	OpenGL *init = new OpenGL();
	init->GetVersion();
	GLFWwindow* window = init->window;
	
	VertexObject* v_o = new VertexObject(0,0);
	v_o->CreateBufferObject();
	v_o->CreateArrayObject();

	VertexShader* v_shader = new VertexShader();
	FragmentShader* f_shader = new FragmentShader();
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, f_shader->GetShader());
	glAttachShader(shaderProgram, v_shader->GetShader());
	glLinkProgram(shaderProgram);

	float angle = 0.01;

	while (!glfwWindowShouldClose(window))
	{
		/* NEBEZPEÈÍ ZAOKROUHLOVÁNÍ - NEPØESNOST
		M = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
		M = glm::rotate(M, 0.01f, glm::vec3(0.0f, 1.0f, 0.0f));
		M = glm::rotate(M, 0.01f, glm::vec3(0.0f, 0.0f, 1.0f));
		M = glm::rotate(M, 0.01f, glm::vec3(1.0f, 0.0f, 0.0f));
		*/

		/*
		M = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
		M = glm::translate(M, glm::vec3(0.0f, 0.5f, 0.0f));
		M = glm::rotate(M, angle, glm::vec3(-1.0f, -1.0f, 1.0f));
		M = glm::translate(M, glm::vec3(0.0f, -0.5f, 0.0f));
		*/

		M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.5f));

		angle = angle + 0.001;
		GLint modelMatrixID = glGetUniformLocation(shaderProgram, "modelMatrix");
		//Render
		glUseProgram(shaderProgram);
		glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, glm::value_ptr(M));

		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(v_o->GetVAO());
		// draw triangles
		glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count
		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

//vertex buffer object (VBO)
/*	GLuint VBO = 0;
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points,
		GL_STATIC_DRAW);
	//vertex attribute object(VAO)
	GLuint VAO = 0;
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	*/