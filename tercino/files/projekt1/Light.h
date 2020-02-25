#pragma once

#include <glm/vec3.hpp> // glm::vec3

class Light
{
	glm::vec3 position;
public:
	Light(glm::vec3 p);
	~Light();

	glm::vec3 getPosition();
};

