#pragma once

#include <stdlib.h>
#include <stdio.h>

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include "Object.h"

class Object;

class Background
{
private:

public:
	std::vector<Object*> objects;
	Background();
	~Background();

	void addObject(Object* object);
	/*void removeObject(Object* object);*/

	void move(glm::vec3 translation);
};

