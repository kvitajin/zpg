#include "ShaderLoader.h"

string ShaderLoader::loadFile(const char* fname)
{
	ifstream file(fname);
	if (!file.is_open())
	{
		cout << "Unable to open file " << fname << endl;
	}
	std::stringstream fileData;
	fileData << file.rdbuf();
	file.close();
	return fileData.str();
}

void ShaderLoader::loadVertexShader(const char* vertexShader, int len)
{
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, (const GLchar**)&vertexShader, &len);
	glCompileShader(vertexID);
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(vertexID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(vertexID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compile failure in Vertex shader:\n%s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

void ShaderLoader::loadFragmentShader(const char* fragmentShader, int len)
{
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, (const GLchar**)&fragmentShader, &len);
	glCompileShader(fragmentID);

	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(fragmentID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(fragmentID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Compile failure in Fragment shader:\n%s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

void ShaderLoader::loadProgram()
{
	programID = glCreateProgram();
	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);
	glLinkProgram(programID);

	glGetProgramiv(programID, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(programID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

GLuint ShaderLoader::loadShader(const char* vertexFile, const char* fragmentFile) {
	printf("Shader::loadShader %s %s \n", vertexFile, fragmentFile);
	string fragmentShaderString = loadFile(fragmentFile);
	string vertexShaderString = loadFile(vertexFile);

	int vlen = vertexShaderString.length();
	int flen = fragmentShaderString.length();

	if (vertexShaderString.empty()) printf("Nulový Vertex Shader\n");
	if (fragmentShaderString.empty()) printf("Nulový Fragment Shader\n");

	const char* vertexShaderCStr = vertexShaderString.c_str();
	const char* fragmentShaderCStr = fragmentShaderString.c_str();

	loadVertexShader(vertexShaderCStr, vlen);
	loadFragmentShader(fragmentShaderCStr, flen);
	loadProgram();

	return programID;
}

void ShaderLoader::deleteShader() {
	printf("ShaderLoader::deleteShader()\n");
	glDetachShader(programID, vertexID);
	glDetachShader(programID, fragmentID);
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
	glUseProgram(0);
	glDeleteProgram(this->programID);
}

ShaderLoader::ShaderLoader(const char* vertexFile, const char* fragmentFile, GLuint* shaderID) {

	*shaderID = loadShader(vertexFile, fragmentFile);
}

ShaderLoader::ShaderLoader()
{
}

ShaderLoader::~ShaderLoader()
{
}
