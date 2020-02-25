#include "ModelObject.h"

void ModelObject::loadMaterials()
{
	for (unsigned int i = 0; i < scene->mNumMaterials; i++)                       //Materials
	{
		this->mat = scene->mMaterials[i];

		aiString name;
		mat->Get(AI_MATKEY_NAME, name);
		printf("Material [%d] name %s\n", i, name.C_Str());

		aiColor4D d;

		glm::vec4 diffuse = glm::vec4(0.8f, 0.8f, 0.8f, 1.0f);
		if (AI_SUCCESS == aiGetMaterialColor(mat, AI_MATKEY_COLOR_DIFFUSE, &d))
			diffuse = glm::vec4(d.r, d.g, d.b, d.a);

		/*std::string base = this->fileName.substr(0, this->fileName.length() - 4) + ".png";
		Texture* texture = new Texture(base.length(), base.c_str());*/

	}
	printf("Materials were loaded\n");
}

void ModelObject::loadObjects()
{
	glm::vec3 maxpos = glm::vec3(0, 0, 0);
	float max_y;
	for (unsigned int i = 0; i < scene->mNumMeshes; i++)
	{
		this->mesh = scene->mMeshes[i];

		max_y = mesh->mVertices[0].y;
		this->pVertices = new Vertex[mesh->mNumVertices];
		std::memset(pVertices, 0, sizeof(Vertex) * mesh->mNumVertices);

		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			if (mesh->mVertices[i].x >= maxpos.x && mesh->mVertices[i].y >= maxpos.y && mesh->mVertices[i].z >= maxpos.z) {
				maxpos.x = mesh->mVertices[i].x;
				maxpos.y = mesh->mVertices[i].y;
				maxpos.z = mesh->mVertices[i].z;
			}
			if (mesh->mVertices[i].y > max_y) {
				max_y = mesh->mVertices[i].y;
			}
			if (mesh->HasPositions())
			{
				pVertices[i].Position[0] = mesh->mVertices[i].x;
				pVertices[i].Position[1] = mesh->mVertices[i].y;
				pVertices[i].Position[2] = mesh->mVertices[i].z;
			}
			if (mesh->HasNormals())
			{
				pVertices[i].Normal[0] = mesh->mNormals[i].x;
				pVertices[i].Normal[1] = mesh->mNormals[i].y;
				pVertices[i].Normal[2] = mesh->mNormals[i].z;
			}
			if (mesh->HasTextureCoords(0))
			{
				pVertices[i].Texture[0] = mesh->mTextureCoords[0][i].x;
				pVertices[i].Texture[1] = mesh->mTextureCoords[0][i].y;
			}
			if (mesh->HasTangentsAndBitangents())
			{
				pVertices[i].Tangent[0] = mesh->mTangents[i].x;
				pVertices[i].Tangent[1] = mesh->mTangents[i].y;
				pVertices[i].Tangent[2] = mesh->mTangents[i].z;
			}

		}
	}

	if (mesh->HasFaces())
	{
		pIndices = new unsigned int[mesh->mNumFaces * 3];
		for (unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			pIndices[i * 3] = mesh->mFaces[i].mIndices[0];
			pIndices[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
			pIndices[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
		}
	}
	//printf("Max vector of objects: %f, %f, %f \n", maxpos.x, maxpos.y, maxpos.z);

	printf("Max y of objects: %f\n", max_y);
	printf("Objects were loaded\n");
}

void ModelObject::loadVertex()
{
	VertexObject* vo = new VertexObject();
	vo->loadModelTexture(this->mesh->mNumVertices, this->mesh->mNumFaces, this->pIndices, this->pVertices);
	this->vao = vo->getVao();
	this->indicesCount = this->mesh->mNumFaces * 3;
}

void ModelObject::load()
{
	Assimp::Importer importer;
	unsigned int importOptions = aiProcess_Triangulate
		| aiProcess_OptimizeMeshes              // slouèení malých plošek
		| aiProcess_JoinIdenticalVertices       // NUTNÉ jinak hodnì duplikuje
		| aiProcess_Triangulate                 // prevod vsech ploch na trojuhelniky
		| aiProcess_CalcTangentSpace;           // vypocet tangenty, nutny pro spravne pouziti normalove mapy


	//aiProcess_GenNormals/ai_Process_GenSmoothNormals - vypocet normal s jemnych prechodem v pripade, ze objekt neobsahuje normaly

	this->scene = importer.ReadFile(this->fileName, importOptions);

	if (scene) {
		printf("scene->mNumMeshes = %d\n", scene->mNumMeshes);
		printf("scene->mNumMaterials = %d\n", scene->mNumMaterials);

		loadMaterials();
		loadObjects();
		loadVertex();

		//delete[] pVertices;
		//delete[] pIndices;
	}
	else {
		printf("Error during parsing mesh from %s : %s \n", this->fileName.c_str(), importer.GetErrorString());
	}
	glBindVertexArray(0);
}


ModelObject::ModelObject(int id, std::string fileName)
{
	this->id = id;
	this->fileName = fileName;
	load();
}

ModelObject::~ModelObject()
{
}
