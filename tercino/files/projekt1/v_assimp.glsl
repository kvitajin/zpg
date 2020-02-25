#version 400
layout(location = 0)in vec3 position;
layout(location = 1)in vec3 normal;
layout(location = 2)in vec2 texture;
layout(location = 3)in vec3 tangent;

uniform vec3 lightPosition;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;

out vec4 ex_worldPosition;
out vec3 ex_worldNormal;
out vec3 ex_worldLight;
out vec3 ex_Tangent;
out vec2 uv;
void main () {
	gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(position, 1.0);
	ex_worldPosition = modelMatrix * vec4(position, 1.0);
	ex_worldNormal = normalMatrix * normal;
	ex_worldLight = lightPosition;
	ex_Tangent = tangent;
	uv = texture;
}