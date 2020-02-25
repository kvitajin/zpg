#pragma once

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/vec3.hpp> // glm::vec3
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <vector>

#include "Shader.h"
#include "Object.h"
#include "OpenGL.h"
#include "SceneObjects.h"

# define M_PI           3.14159265358979323846

class Shader;
class Object;

class Camera
{
private:
	double x = 0.0f;
	double y = 0.0f;
	double alpha = -M_PI / 2;
	double fi = M_PI / 2;

	bool movement = false;

	glm::vec2 oldPosition;

	glm::vec3 eye = glm::vec3(0.0f, 3.0f, 20.0f);
	glm::vec3 target = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	static Camera* instance;
	std::vector<Shader*> list;
	std::vector<Object*> background;

	Camera();
public:
	static Camera* GetInstance();

	void AddShader(Shader* shader);
	void RemoveShader(Shader* shader);
	void IsChanged();

	void setBackground(std::vector<Object*> bg);
	void SetView();
	void SetTarget();
	void SetMovement();
	void SetClickedPosition(double x, double y);

	GLuint GetStencilIndex();
	glm::vec2 getClickPosition();
	glm::mat4 GetViewMatrix(void);
	glm::mat4 GetProjectionMatrix(void);
	glm::vec3 get3DPosition();

	void MouseUpdate(double x, double y);

	void ToFront();
	void ToBack();
	void ToLeft();
	void ToRight();

	void TurnRight();
	void TurnLeft();
	void Up();
	void Down();
};


