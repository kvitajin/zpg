#include "Renderer.h"


Renderer::Renderer(Shader* shader)
{
	this->shader = shader;
}

Renderer::~Renderer()
{
}

void Renderer::draw()
{
	if (IsDrawable()) {
		std::vector<Object*> objects = SceneObjects::getInstance()->getAllObjects();

		for (unsigned int i = 0; i < objects.size(); i++) {
			Object* o = objects[i];
			if (o->getType() == Enemy) {
				glStencilFunc(GL_ALWAYS, o->getID(), 0xFF);
			}

			switch (o->getShaderType())
			{
			case AssimpShader:
				shader->setModelMatrix(o->getModelMat());
				glBindTexture(GL_TEXTURE_2D, o->getTexture());
				glBindVertexArray(o->getVao());
				shader->useProgram(shaderAssimp, AssimpShader);
				/* NORMALOVÉ MAPY
				if (o->getType() == Enemy) {
					glActiveTexture(GL_TEXTURE0);
					GLuint textureID = SOIL_load_OGL_texture("ghostNormal.png", SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
					glBindTexture(GL_TEXTURE_2D, textureID);
					shader->setNormalTexture();
				}
				glBindTexture(GL_TEXTURE_2D, o->getTexture());*/
				glDrawElements(GL_TRIANGLES, o->getIndices(), GL_UNSIGNED_INT, NULL);
				break;

			case TextureShader:
				shader->setModelMatrix(o->getModelMat());
				glBindTexture(GL_TEXTURE_2D, o->getTexture());
				glBindVertexArray(o->getVao());
				shader->useProgram(shaderTexture, TextureShader);
				glDrawArrays(GL_TRIANGLES, 0, o->getSize());
				break;

			case PhongShader:
				shader->setModelMatrix(o->getModelMat());
				glBindVertexArray(o->getVao());
				shader->useProgram(shaderPhong, PhongShader);
				glDrawArrays(GL_TRIANGLES, 0, o->getSize());
				break;

			default:
				break;
			}
		}
	}
}

bool Renderer::IsDrawable()
{
	if (shaderAssimp != -1 && shaderPhong != -1 && shaderTexture != -1)
		return true;
	return false;
}
