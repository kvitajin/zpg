#include "Texture.h"

Texture::Texture(const char* name, const char* file)
{
	this->name = name;
	this->filename = file;
	load();
}

Texture::~Texture()
{
}

GLuint Texture::getTextureId()
{
	return this->textureID;
}

const char* Texture::getName()
{
	return this->name;
}

void Texture::load()
{
	glActiveTexture(GL_TEXTURE0);
	this->textureID = SOIL_load_OGL_texture(this->filename, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
}


