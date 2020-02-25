#include "Camera.h"
#include "Shader.h"

Camera* Camera::instance = NULL;

Camera::Camera()
{
}

Camera* Camera::GetInstance()
{
	if (instance == 0) {
		instance = new Camera;
	}
	return instance;
}

void Camera::AddShader(Shader* shader)
{
	this->list.push_back(shader);
}

void Camera::RemoveShader(Shader* shader)
{
	std::vector<Shader*>::iterator it = std::find(list.begin(), list.end(), shader);
	this->list.erase(it);
}

void Camera::IsChanged()
{
	//printf("Eye: %f, %f, %f\n", this->eye.x, this->eye.y, this->eye.z);
	//printf("Target: %f, %f, %f\n", this->target.x, this->target.y, this->target.z);
	//printf("Up: %f, %f, %f\n", this->up.x, this->up.y, this->up.z);

	for (unsigned int i = 0; i < list.size(); i++) {
		this->list.at(i)->cameraIsMoved(this);
	}
}

void Camera::setBackground(std::vector<Object*> bg)
{
	this->background = bg;
}

void Camera::SetView()
{
	if (this->alpha < 1.5f && this->alpha > -1.5f) {
		this->alpha += 0.01f;
		target.x = sin(this->alpha) * cos(this->fi);
		target.z = cos(this->alpha);
		target.y = sin(this->alpha) * cos(this->fi);
		printf("targ: [%f,%f,%f]\n", target.x, target.y, target.z);
		this->IsChanged();
	}
}

void Camera::SetTarget()
{
	target.x = sin(this->alpha) * cos(this->fi);
	target.y = cos(this->alpha);
	target.z = sin(this->alpha) * sin(this->fi);
	printf("targ: [%f,%f,%f]\n", target.x, target.y, target.z);
	this->IsChanged();
}

void Camera::SetMovement()
{
	this->movement = !this->movement;
}

void Camera::SetClickedPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}

glm::mat4 Camera::GetViewMatrix(void) {
	return glm::lookAt(eye, eye + target, up);
}

glm::mat4 Camera::GetProjectionMatrix(void)
{
	return glm::perspective(120.0f, 4.0f / 3.0f, 0.01f, 100.0f);
}

GLuint Camera::GetStencilIndex() {
	int window_width = OpenGL::getInstance()->getWidth();
	int window_height = OpenGL::getInstance()->getHeight();

	GLuint index;
	double newy = window_height - this->y;

	glReadPixels(this->x, (GLint)newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);
	return index;
}

glm::vec3 Camera::get3DPosition()
{
	int window_width = OpenGL::getInstance()->getWidth();
	int window_height = OpenGL::getInstance()->getHeight();

	GLbyte color[4];
	GLfloat depth;
	GLuint index;
	double newy = window_height - this->y;

	glReadPixels(this->x, (GLint)newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
	glReadPixels(this->x, (GLint)newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
	glReadPixels(this->x, (GLint)newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

	//printf("Clicked on pixel %f, %f, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index %u\n", x, y, color[0], color[1], color[2], color[3], depth, index);

	glm::vec3 screenX = glm::vec3(this->x, newy, depth);
	glm::mat4 view = Camera::GetInstance()->GetViewMatrix();
	glm::mat4 projection = Camera::GetInstance()->GetProjectionMatrix();

	glm::vec4 viewPort = glm::vec4(0, 0, window_height, window_width);

	return glm::unProject(screenX, view, projection, viewPort);
}

void Camera::MouseUpdate(double x, double y)
{
	if (movement) {
		glm::mat4 M = glm::mat4(1.0f);
		glm::vec2 newPosition = glm::vec2(x, y);
		glm::vec2 mouseDelta = newPosition - oldPosition;
		if (glm::length(mouseDelta) > 50.0f) {
			oldPosition = newPosition;
			return;
		}
		const float speed = 0.005f;
		glm::vec3 toRotate = glm::cross(this->target, this->up);
		glm::mat4 rotator = glm::rotate(M, -mouseDelta.x * speed, this->up) *
			glm::rotate(M, -mouseDelta.y * speed, toRotate);
		this->target = glm::mat3(rotator) * this->target;
		oldPosition = newPosition;
		this->IsChanged();
	}
}

void Camera::ToFront()
{
	glm::vec3 t = (glm::normalize(target));
	eye += t;
	this->IsChanged();
}
void Camera::ToBack()
{
	glm::vec3 t = (glm::normalize(target));
	eye -= t;
	this->IsChanged();
}
void Camera::ToLeft()
{
	glm::vec3 t = (glm::normalize(glm::cross(target, up)));
	eye -= t;
	this->IsChanged();
}
void Camera::ToRight()
{
	glm::vec3 t = (glm::normalize(glm::cross(target, up)));
	eye += t;
	this->IsChanged();
}


void Camera::TurnRight()
{
	this->fi += 0.01f;
	this->SetTarget();
}
void Camera::TurnLeft()
{
	this->fi -= 0.01f;
	this->SetTarget();
}
void Camera::Up()
{
	if (this->alpha < 0) {
		this->alpha += 0.01f;
		this->SetTarget();
	}
}
void Camera::Down()
{
	if (this->alpha > -M_PI) {
		this->alpha -= 0.01f;
		this->SetTarget();
	}
}

glm::vec2 Camera::getClickPosition()
{
	return glm::vec2(this->x, this->y);
}
