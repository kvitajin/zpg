#include "Background.h"



Background::Background()
{
}


Background::~Background()
{
}

void Background::addObject(Object* object)
{
	objects.push_back(object);
}
//
//void Background::removeObject(Object* object)
//{
//}

void Background::move(glm::vec3 translation)
{
	for (unsigned int i = 0; i < objects.size(); i++) {

		objects[i]->move(translation);
	}
}
