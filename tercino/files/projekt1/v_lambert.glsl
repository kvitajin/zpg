#version 400
layout(location = 0)in vec3 position;
layout(location = 1)in vec3 normal;
out vec4 ex_worldPosition;
out vec3 ex_worldNormal;
uniform vec3 lightPosition;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;
void main(){
	gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(position, 1.0);
	ex_worldPosition = modelMatrix * vec4(position, 1.0);
	ex_worldNormal = normal;
}
