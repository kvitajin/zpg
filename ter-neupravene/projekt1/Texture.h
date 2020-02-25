#pragma once

#include <SOIL.h>

#include <GL/glew.h>

class Texture
{
private:
	GLuint textureID;
	const char* name;
	const char* filename;

	void load();

public:
	Texture(const char* name, const char* file);
	~Texture();

	GLuint getTextureId();
	const char* getName();
};

