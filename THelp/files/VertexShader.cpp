#include "VertexShader.h"

VertexShader::VertexShader()
{
	//LESSON 2
	/*this->str_shader =
		"#version 330\n"
		"layout(location=0) in vec3 vp;"
		"void main () {"
		"     gl_Position = vec4 (vp, 1.0);"
		"}";*/
	float tmp[16]={
	        1,0,0,0,
	        0,1,0,0,
	        0,0,1,0,
	        0,0,0,1
	};
    this->str_shader = "#version 400\n"
                       "uniform mat4 modelMatrix;"
                       "layout(location=0) in vec3 vp;"
                       "uniform mat4 viewMatrix=mat4(1.0);"
                       "uniform mat4 projectionMatrix=mat4(1.0);"
                       "void main () {"
                       " gl_Position = (projectionMatrix * viewMatrix *  modelMatrix) * vec4 (vp, 1.0);"
                       "}";

	this->shader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(this->shader, 1, &this->str_shader, NULL);
	glCompileShader(this->shader);

}


VertexShader::~VertexShader()
{
}

GLuint VertexShader::GetShader()
{
	return this->shader;
}
