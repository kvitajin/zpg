#include "SceneObjects.h"
#include <algorithm>

SceneObjects* SceneObjects::instance = NULL;

SceneObjects::SceneObjects()
{
}


SceneObjects::~SceneObjects()
{
}

SceneObjects* SceneObjects::getInstance()
{
	if (instance == 0) {
		instance = new SceneObjects;
	}
	return instance;
}

std::vector<Object*> SceneObjects::getAllObjects()
{
	std::vector<Object*> all = this->enemies;
	all.insert(all.end(),
		this->staticObjects.begin(),
		this->staticObjects.end());
	all.insert(all.end(),
		this->background.begin(),
		this->background.end());
	return all;
}

std::vector<Object*> SceneObjects::getEnemies()
{
	return this->enemies;
}

std::vector<Object*> SceneObjects::getStaticObjects()
{
	return this->staticObjects;
}

std::vector<Object*> SceneObjects::getBackground()
{
	return this->background;
}

void SceneObjects::moveBackground(glm::vec3 t)
{
	for (unsigned int i = 0; i < this->background.size(); i++)
	{
		Object* o = this->background[i];
		o->modelMatrix = glm::translate(glm::mat4(1.0), glm::vec3(t.x, 0.1, t.z));
		o->modelMatrix = glm::scale(o->modelMatrix, glm::vec3(8.0, 8.0, 8.0));
	}
}

void SceneObjects::addObject(Object* object)
{
	if (object->getType() == Static) {
		this->staticObjects.push_back(object);
	}
	else if (object->getType() == Enemy) {
		this->enemies.push_back(object);
	}
	else if (object->getType() == Background) {
		this->background.push_back(object);
	}
}


void SceneObjects::removeObject(Object* object)
{
	switch (object->getType()) {
	case Enemy:
		this->enemies.erase(
			std::remove(
				begin(this->enemies),
				end(this->enemies),
				object),
			end(this->enemies));
		break;
	case Static:
		this->staticObjects.erase(
			std::remove(
				begin(this->staticObjects),
				end(this->staticObjects),
				object),
			end(this->staticObjects));
		break;
	case Background:
		this->background.erase(
			std::remove(
				begin(this->background),
				end(this->background),
				object),
			end(this->background));
		break;
	}
}

void SceneObjects::removeObject(int id)
{
	std::vector<Object*> all = getAllObjects();

	for (unsigned int i = 0; i < all.size(); i++) {
		if (all[i]->getID() == id) {
			removeObject(all[i]);
			return;
		}
	}
}
