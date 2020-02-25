#include <GL/glew.h>
#include "files/ShaderLoader.h"

ShaderLoader *loader = new ShaderLoader();
GLuint shaderProgram = loader->loadShader("./shaders/vertex.glsl", "./shaders/fragment.glsl");