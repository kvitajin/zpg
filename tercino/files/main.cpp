#include "projekt1/ShaderLoader.h"

ShaderLoader *loader = new ShaderLoader();
GLuint shaderProgram = loader->loadShader("./shaders/vertex.glsl", "./shaders/fragment.glsl");