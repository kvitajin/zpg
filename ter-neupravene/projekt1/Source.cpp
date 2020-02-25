
//Include GLEW
#include <GL/glew.h>

//Include GLFW
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
#include <Windows.h>
#include <math.h> 


#include "OpenGL.h"
#include "VertexObject.h"
#include "Object.h"
#include "Camera.h"
#include "ShaderLoader.h"
#include "Model.h"
#include "Texture.h"

#include "Application.h"


std::vector<Object*> balls;

static void error_callback(int error, const char* description) { fputs(description, stderr); }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	switch (key) {
	case GLFW_KEY_RIGHT:
		Camera::GetInstance()->ToRight();
		break;
	case GLFW_KEY_LEFT:
		Camera::GetInstance()->ToLeft();
		break;
	case GLFW_KEY_UP:
		Camera::GetInstance()->ToFront();
		break;
	case GLFW_KEY_DOWN:
		Camera::GetInstance()->ToBack();
		break;
	case GLFW_KEY_W:
		Camera::GetInstance()->Up();
		break;
	case GLFW_KEY_S:
		Camera::GetInstance()->Down();
		break;
	case GLFW_KEY_A:
		Camera::GetInstance()->TurnLeft();
		break;
	case GLFW_KEY_D:
		Camera::GetInstance()->TurnRight();
		break;
	}
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

static void window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

static void window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

static void window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

static void cursor_callback(GLFWwindow* window, double x, double y) {
	Camera::GetInstance()->SetClickedPosition(x, y);
	Camera::GetInstance()->MouseUpdate(x, y);
	//printf("cursor_callback: [%f,%f] \n", x, y);
}

static void button_callback(GLFWwindow* window, int button, int action, int mode) {

	if (action == GLFW_PRESS) {
		printf("button_callback [%d,%d,%d]\n", button, action, mode);
		if (button == 1) {
			Camera::GetInstance()->SetMovement();
		}
		else {
			int stencil = Camera::GetInstance()->GetStencilIndex();
			int idx = -1;
			for (unsigned int i = 0; i < balls.size(); i++) {
				if (balls[i]->getID() == stencil) {
					idx = i;
					break;
				}
			}
			if (idx != -1) {
				balls.erase(balls.begin() + idx);
			}
			glm::vec3 pos = Camera::GetInstance()->get3DPosition();
			printf("unProject[%f, %f, %f]\n", pos.x, pos.y, pos.z);
		}
	}
}

glm::mat4 M = glm::mat4(1.0f);

int main(void)
{
	Application::GetInstance();

	//glfwSetErrorCallback(error_callback);
	//if (!glfwInit()) {
	//	fprintf(stderr, "ERROR: could not start GLFW3\n");
	//	exit(EXIT_FAILURE);
	//}

	//OpenGL::getInstance()->printVersion();
	//GLFWwindow* window = OpenGL::getInstance()->window;

	//Shader* shader = new Shader();
	//Camera::GetInstance()->AddShader(shader);
	//shader->addLight(new Light(glm::vec3(0, 20, 200)));

	//ShaderLoader* phongLoader = new ShaderLoader();
	//GLuint shaderBall = phongLoader->loadShader("./v_phong.glsl", "./f_phong.glsl");

	//ShaderLoader* textureLoader = new ShaderLoader();
	//GLuint shaderTexture = textureLoader->loadShader("./v_texture.glsl", "./f_texture.glsl");

	//ShaderLoader* assimpLoader = new ShaderLoader();
	//GLuint shaderAssimp = assimpLoader->loadShader("./v_assimp.glsl", "./f_assimp.glsl");

	//VertexObject* v_o = new VertexObject();
	//v_o->loadBall();

	//VertexObject* plain = new VertexObject();
	//plain->loadPlainTexture();

	//Background* background = new Background();
	//glm::mat4 ballMat = glm::scale(M, glm::vec3(0.2, 0.2, 0.2));
	//Object* ball = new Object(8, v_o->getVao(), glm::translate(ballMat, glm::vec3(-10.0, 2.0, 50)));
	///*balls.push_back(new Object(5, v_o->getID(), glm::translate(M, glm::vec3(5.0, 0.0, 10.0))));
	//balls.push_back(new Object(6, v_o->getID(), glm::translate(M, glm::vec3(-5.0, 0.0, 10.0))));
	//balls.push_back(new Object(7, v_o->getID(), glm::translate(M, glm::vec3(0.0, 5.0, 10.0))));
	//balls.push_back(new Object(8, v_o->getID(), glm::translate(M, glm::vec3(0.0, -5.0, 10.0))));*/
	//balls.push_back(ball);

	//Model* sky = new Model("skydome.obj");
	//Object* skyobj = new Object(27, sky->getVao(), glm::scale(M, glm::vec3(10.0, 10.0, 10.0)));
	//background->addObject(skyobj);;
	//Camera::GetInstance()->setBackground(background);

	//Model* model = new Model("test.obj");
	//Texture* skytext = new Texture("sky", "skydome.png");
	//Texture* plaintext = new Texture("trava", "trava.jpg");
	//Texture* modeltext = new Texture("test", "test.png");

	//int counter = 0;
	//bool direct = true;

	//while (!glfwWindowShouldClose(window))
	//{

	//	// clear color and depth buffer
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	glEnable(GL_DEPTH_TEST);
	//	glEnable(GL_STENCIL_TEST);
	//	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	//	if (direct && balls.size() != 0) {
	//		if (counter != 60) {
	//			balls[0]->modelMatrix = glm::translate(balls[0]->modelMatrix, glm::vec3(0.4, 0.0, 0.0));
	//			balls[0]->setModelMatrixInShader(shader);
	//			counter++;
	//		}
	//		else {
	//			direct = false;
	//		}
	//	}
	//	else {
	//		if (counter != 0 && balls.size() != 0) {
	//			balls[0]->modelMatrix = glm::translate(balls[0]->modelMatrix, glm::vec3(-0.4, 0.0, 0.0));
	//			balls[0]->setModelMatrixInShader(shader);
	//			counter--;
	//		}
	//		else {
	//			direct = true;
	//		}
	//	}
	//	glBindTexture(GL_TEXTURE_2D, plaintext->getTextureId());
	//	glm::mat4 plainModelMat = glm::scale(M, glm::vec3(80.0, 80.0, 80.0));
	//	//plainModelMat = glm::translate(plainModelMat, glm::vec3(0, 0.01, 0));
	//	shader->setModelMatrix(plainModelMat);
	//	shader->useProgram(shaderTexture, TextureShader);
	//	glBindVertexArray(plain->getVao());
	//	glDrawArrays(GL_TRIANGLES, 0, 6);

	//	/*shader->setModelMatrix(glm::scale(M, glm::vec3(12, 12, 12)));
	//	glBindTexture(GL_TEXTURE_2D, skytext->getTextureId());
	//	shader->useProgram(shaderAssimp, AssimpShader);
	//	glBindVertexArray(sky->getVao());
	//	glDrawElements(GL_TRIANGLES, sky->getIndices(), GL_UNSIGNED_INT, NULL);*/

	//	for (int i = 0; i < background->objects.size(); i++) {
	//		background->objects[i]->setModelMatrixInShader(shader);
	//		glBindTexture(GL_TEXTURE_2D, skytext->getTextureId());
	//		shader->useProgram(shaderAssimp, AssimpShader);
	//		glBindVertexArray(background->objects[i]->getVao());
	//		glDrawElements(GL_TRIANGLES, sky->getIndices(), GL_UNSIGNED_INT, NULL);
	//	}

	//	shader->useProgram(shaderBall, PhongShader);
	//	glBindVertexArray(v_o->getVao());
	//	for (int i = 0; i < balls.size(); i++) {
	//		balls[i]->setModelMatrixInShader(shader);
	//		glStencilFunc(GL_ALWAYS, balls[i]->getID(), 0xFF);
	//		glDrawArrays(GL_TRIANGLES, 0, 2880);
	//	}

	//	shader->setModelMatrix(M);
	//	glBindTexture(GL_TEXTURE_2D, modeltext->getTextureId());
	//	shader->useProgram(shaderAssimp, AssimpShader);
	//	glBindVertexArray(model->getVao());
	//	glDrawElements(GL_TRIANGLES, model->getIndices(), GL_UNSIGNED_INT, NULL);

	//	glfwSetMouseButtonCallback(window, button_callback);
	//	glfwSetKeyCallback(window, key_callback);
	//	glfwSetCursorPosCallback(window, cursor_callback);

	//	// update other events like input handling
	//	glfwPollEvents();
	//	// put the stuff we’ve been drawing onto the display
	//	glfwSwapBuffers(window);
	//}

	//glfwDestroyWindow(window);
	//glfwTerminate();
	//exit(EXIT_SUCCESS);
}
