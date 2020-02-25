#include "Light.h"


Light::Light(glm::vec3 p)
{
	this->position = p;
}

Light::~Light()
{
}

glm::vec3 Light::getPosition()
{
	return this->position;
}
