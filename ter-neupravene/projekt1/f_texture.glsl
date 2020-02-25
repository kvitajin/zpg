#version 400

uniform sampler2D textureUnitID;

in vec2 uv;
in vec4 ex_worldPosition;
in vec3 ex_worldNormal;
in vec3 ex_worldLight;

out vec4 frag_colour;

vec4 getAmbient()
{
	return vec4( 0.1, 0.1, 0.1, 1.0);
}

vec4 getDiffuse(vec3 lightVector)
{
	float dot_product = max(dot(normalize(-lightVector), normalize(ex_worldNormal)), 0.0); 
	return dot_product * vec4( 0.385, 0.647, 0.812, 1.0);
}

vec4 getSpecular(vec3 viewVector, vec3 reflectVector)
{
	float spec = pow(max(dot(normalize(viewVector), normalize(reflectVector)), 0.0), 8);
	return 0.8 * spec * vec4( 1.0, 1.0, 1.0, 1.0);
}

void main (void) {
	vec3 lightVector = vec3(ex_worldPosition) - ex_worldLight;
	vec3 viewVector = - vec3(ex_worldPosition);
	vec3 reflectVector = reflect(lightVector,ex_worldNormal);

	float dot_product = max(dot(normalize(-lightVector), normalize(ex_worldNormal)), 0.0); 
	float spec = pow(max(dot(normalize(viewVector), normalize(reflectVector)), 0.0), 8);
	
	vec4 ambient = getAmbient();
	vec4 diffuse = getDiffuse(lightVector);
	vec4 specular = getSpecular(viewVector, reflectVector);

	frag_colour = texture(textureUnitID, uv);
}
