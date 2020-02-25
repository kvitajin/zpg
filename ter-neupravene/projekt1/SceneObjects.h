#pragma once

#include "Background.h"
#include "Object.h"

class SceneObjects
{
private:
	std::vector<Object*> background;
	std::vector<Object*> enemies;
	std::vector<Object*> staticObjects;

	static SceneObjects* instance;
	SceneObjects();

public:
	~SceneObjects();
	static SceneObjects* getInstance();

	std::vector<Object*> getAllObjects();
	std::vector<Object*> getEnemies();
	std::vector<Object*> getStaticObjects();
	std::vector<Object*> getBackground();

	void moveBackground(glm::vec3 t);

	void addObject(Object* object);
	void removeObject(Object* object);
	void removeObject(int id);
};

