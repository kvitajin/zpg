#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>  
#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "ShaderLoader.h"
#include "VertexObject.h"
#include "VertexStruct.h"
#include "Object.h"

class Object;

class Model : public Object
{
private:
	std::string fileName;

	const aiScene* scene;
	const aiMaterial* mat;
	aiMesh* mesh;
	unsigned int* pIndices = nullptr;

	void loadMaterials();
	void loadObjects();
	void loadVertex();

public:
	Model(int id, std::string fileName);
	Model(int id, ObjectType type, std::string fileName);
	~Model();

	void load();
};
