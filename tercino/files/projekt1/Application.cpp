#include "Application.h"

#include "first.h"
#include "second.h"
# define M_PI           3.14159265358979323846

Application* Application::instance = NULL;

Application::Application()
{
	run();
}

Application* Application::GetInstance()
{
	if (instance == 0) {
		instance = new Application;
	}
	return instance;
}

Application::~Application()
{
}

void Application::error_callback(int error, const char* description) { fputs(description, stderr); }

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
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
	//printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Application::window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

void Application::window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

void Application::window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void Application::cursor_callback(GLFWwindow* window, double x, double y) {
	Camera::GetInstance()->SetClickedPosition(x, y);
	Camera::GetInstance()->MouseUpdate(x, y);
	//printf("cursor_callback: [%f,%f] \n", x, y);
}

void Application::button_callback(GLFWwindow* window, int button, int action, int mode) {

	if (action == GLFW_PRESS) {
		printf("button_callback [%d,%d,%d]\n", button, action, mode);
		if (button == 1) {
			Camera::GetInstance()->SetMovement();
		}
		else {
			instance->removeObjectOnClick();
			glm::vec3 pos = Camera::GetInstance()->get3DPosition();
			printf("unProject[%f, %f, %f]\n", pos.x, pos.y, pos.z);
		}
	}
}


void Application::run()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	OpenGL::getInstance()->printVersion();
	GLFWwindow* window = OpenGL::getInstance()->window;

	Shader* shader = new Shader();
	this->renderer = new Renderer(shader);
	Camera::GetInstance()->AddShader(shader);
	Camera::GetInstance()->SetTarget();
	shader->addLight(new Light(glm::vec3(0, 200, 200)));

	shader->addLight(new Light(glm::vec3(0, 40, 0)));
	shader->addLight(new Light(glm::vec3(100, 40, 50)));
	shader->addLight(new Light(glm::vec3(0, 40, 10)));
	shader->addLight(new Light(glm::vec3(-100, 40, 50)));

	loadRender();
	loadObjects();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_STENCIL_TEST);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

		this->renderer->draw();

		glfwSetCursorPosCallback(window, cursor_callback);
		glfwSetMouseButtonCallback(window, button_callback);
		glfwSetKeyCallback(window, key_callback);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void Application::removeObjectOnClick()
{
	int stencil = Camera::GetInstance()->GetStencilIndex();
	std::vector<Object*> enemies = SceneObjects::getInstance()->getEnemies();
	for (unsigned int i = 0; i < enemies.size(); i++) {
		if (enemies[i]->getID() == stencil) {
			SceneObjects::getInstance()->removeObject(enemies[i]);
			break;
		}
	}
}

void Application::loadRender()
{
	ShaderLoader* phongLoader = new ShaderLoader();
	renderer->shaderPhong = phongLoader->loadShader("./v_phong.glsl", "./f_phong.glsl");

	ShaderLoader* textureLoader = new ShaderLoader();
	renderer->shaderTexture = textureLoader->loadShader("./v_texture.glsl", "./f_texture.glsl");

	ShaderLoader* assimpLoader = new ShaderLoader();
	renderer->shaderAssimp = assimpLoader->loadShader("./v_assimp.glsl", "./f_assimp.glsl");
}

void Application::setBackground()
{
	VertexObject* vao = new VertexObject();

	vao->loadPlainTexture();
	glm::mat4 plainModelMat = glm::scale(M, glm::vec3(80.0, 80.0, 80.0));
	Object* plain = new Object(autoId++, 6, vao->getVao(), Background, plainModelMat);
	plain->setTexture(new Texture("trava", "trava.jpg"));
	plain->setShaderType(TextureShader);
	SceneObjects::getInstance()->addObject(plain);

	Model* sky = new Model(autoId++, Background, "skydome.obj");
	sky->setTexture(new Texture("sky", "skydome.png"));
	sky->modelMatrix = glm::scale(M, glm::vec3(8.0, 8.0, 8.0));
	sky->setShaderType(AssimpShader);
	SceneObjects::getInstance()->addObject((Object*)sky);
}

void Application::loadObjects()
{
	setBackground();

	Model* building = new Model(autoId++, Static, "../Models/house/test.obj");
	building->setTexture(new Texture("test", "../Models/house/test.png"));
	building->setShaderType(AssimpShader);
	building->modelMatrix = M;
	SceneObjects::getInstance()->addObject((Object*)building);
	Object* building2 = new Object();
	*building2 = *building;
	building2->setShaderType(AssimpShader);
	building2->modelMatrix = glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(-20, 0, -20)), (float)M_PI / 2, glm::vec3(0.0f, 1.0f, 0.0f));
	SceneObjects::getInstance()->addObject(building2);

	Model* cottage = new Model(autoId++, Static, "../Models/cottage/cottage.obj");
	cottage->setTexture(new Texture("cottage", "../Models/cottage/cottage.png"));
	cottage->setShaderType(AssimpShader);
	cottage->modelMatrix = glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(-13, 0, 10)), (float)M_PI, glm::vec3(0.0f, 1.0f, 0.0f));
	SceneObjects::getInstance()->addObject((Object*)cottage);

	Model* log = new Model(autoId++, Static, "../Models/log/log.obj");
	log->setTexture(new Texture("log", "../Models/log/log_diffuse.png"));
	log->setShaderType(AssimpShader);
	log->modelMatrix = glm::rotate(glm::translate(glm::scale(glm::mat4(1.0f), glm::vec3(0.01, 0.01, 0.01)), glm::vec3(-50, 0, 1300)), (float)M_PI / 8, glm::vec3(0, 1, 0));
	SceneObjects::getInstance()->addObject((Object*)log);

	Model* ghost1 = new Model(autoId++, Enemy, "../Models/ghost/ghost.obj");
	ghost1->setTexture(new Texture("ghost", "../Models/ghost/ghost.png"));
	ghost1->setShaderType(AssimpShader);
	glm::mat4 modelMat = glm::scale(M, glm::vec3(0.01, 0.01, 0.01));
	modelMat = glm::translate(modelMat, glm::vec3(-250.0, 2.0, 1000));
	ghost1->modelMatrix = modelMat;
	//ghost->setMovement(glm::vec3(500.0, 0, 0)); pøímka
	ghost1->setMovement(first_curve);
	SceneObjects::getInstance()->addObject((Object*)ghost1);


	Object* ghost = new Object();
	*ghost = *ghost1;
	ghost->setID(autoId++);
	modelMat = glm::scale(M, glm::vec3(0.01, 0.01, 0.01));
	modelMat = glm::translate(modelMat, glm::vec3(350.0, 2.0, 500));
	ghost->modelMatrix = modelMat;
	ghost->setMovement(first_curve);
	SceneObjects::getInstance()->addObject((Object*)ghost);

	Object* ghost2 = new Object();
	*ghost2 = *ghost1;
	ghost2->setID(autoId++);
	modelMat = glm::scale(M, glm::vec3(0.01, 0.01, 0.01));
	modelMat = glm::translate(modelMat, glm::vec3(1200.0, 2.0, 0));
	ghost2->modelMatrix = modelMat;
	ghost2->setMovement(first_curve);
	SceneObjects::getInstance()->addObject((Object*)ghost2);

	Object* ghost3 = new Object();
	*ghost3 = *ghost1;
	ghost3->setID(autoId++);
	modelMat = glm::scale(M, glm::vec3(0.01, 0.01, 0.01));
	modelMat = glm::translate(modelMat, glm::vec3(-800.0, 2.0, 0));
	ghost3->modelMatrix = modelMat;
	ghost3->setMovement(first_curve);
	SceneObjects::getInstance()->addObject((Object*)ghost3);

	Model* stump = new Model(autoId++, Static, "../Models/stump/stump.obj");
	stump->setTexture(new Texture("stump", "../Models/stump/stump.png"));
	stump->setShaderType(AssimpShader);
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			Object* s = new Object();
			*s = *stump;
			s->modelMatrix = glm::translate(glm::mat4(1.0), glm::vec3((-5) * i, 0, (-2) * j));
			SceneObjects::getInstance()->addObject(s);

			Object* t = new Object();
			*t = *stump;
			t->modelMatrix = glm::translate(glm::mat4(1.0), glm::vec3(8 + (2 * i), 0, 5 + (3 * j)));
			SceneObjects::getInstance()->addObject(t);
		}
	}
}



//Model* ghost2 = new Model(autoId++, Enemy, "ghost.obj");
//ghost2->setTexture(new Texture("ghost", "ghost.png"));
//ghost2->setShaderType(AssimpShader);
//modelMat = glm::scale(M, glm::vec3(0.01, 0.01, 0.01));
//modelMat = glm::translate(modelMat, glm::vec3(-300.0, 2.0, 1000));
//ghost2->modelMatrix = modelMat;
////ghost->setMovement(glm::vec3(500.0, 0, 0));
//ghost2->setMovement(infinity);
//SceneObjects::getInstance()->addObject((Object*)ghost2);


//Model* ghost = new Model(autoId++, Enemy, "ghost.obj");
//ghost->setTexture(new Texture("ghost", "ghost.png"));
//ghost->setShaderType(AssimpShader);
//modelMat = glm::scale(M, glm::vec3(0.01, 0.01, 0.01));
//modelMat = glm::translate(modelMat, glm::vec3(350.0, 2.0, 500));
//ghost->modelMatrix = modelMat;
////ghost->setMovement(glm::vec3(500.0, 0, 0));
//ghost->setMovement(infinity);
//SceneObjects::getInstance()->addObject((Object*)ghost);

/*VertexObject* obj = new VertexObject();
	obj->loadBall();
	Object* ball = new Object(autoId++, 2880, obj->getVao(), Enemy);
	ball->modelMatrix = glm::translate(glm::mat4(1.0), glm::vec3(5, 2, 12));
	ball->setShaderType(PhongShader);
	ball->setMovement(infinity);
	SceneObjects::getInstance()->addObject(ball);
	*/