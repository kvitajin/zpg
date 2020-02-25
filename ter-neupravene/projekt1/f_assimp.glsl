#version 400

#define MAX_LIGHTS 8

in vec4 ex_worldPosition;
in vec3 ex_worldNormal;
in vec3 ex_worldLight;
in vec3 ex_Tangent;
in vec2 uv;

out vec4 frag_colour;

uniform int numberOflights;
uniform vec3 lights[MAX_LIGHTS];

uniform sampler2D textureUnitID;
uniform sampler2D normalTexture;
uniform bool isNormalTexure;

vec3 CalcNormal() {
	vec3 Normal = normalize(ex_worldNormal);
	vec3 Tangent = normalize(ex_Tangent);

	//Gram–Schmidt process
	Tangent = normalize(Tangent - dot(Tangent, Normal) * Normal);
	vec3 Bitangent = cross(Tangent, Normal);
	vec3 BumpMapNormal = texture(normalTexture, uv).xyz;

	//pøevod z vektoru barvy o rozsahu <0,1> do vektoru normály <-1,1>
	BumpMapNormal = 2.0 * BumpMapNormal - vec3(1.0, 1.0, 1.0);

	// Transformaèní matice TBN
	mat3 TBN = mat3(Tangent, Bitangent, Normal);
	return normalize(TBN * BumpMapNormal);
}

vec4 getAmbient()
{
	return vec4( 0.1, 0.1, 0.1, 1.0);
}

vec4 getDiffuse(vec3 lightVector)
{
	/*float dot_product;
	for(int i = 0; i < numberOflights; i++)
	{
		dot_product = dot_product + max(dot(normalize(-lights[i]), normalize(ex_worldNormal)), 0.0); 
	}*/
	float dot_product = max(dot(normalize(lightVector), normalize(ex_worldNormal)), 0.0); 
	return dot_product * vec4( 0.385, 0.647, 0.812, 1.0);
}

vec4 getSpecular(vec3 viewVector, vec3 reflectVector)
{
	float spec = pow(max(dot(normalize(viewVector), normalize(reflectVector)), 0.0), 8);
	return 0.8 * spec * vec4( 1.0, 1.0, 1.0, 1.0);
}

void main (void) {

	if(isNormalTexure){
		vec3 ex_worldNormal = CalcNormal();
	}

	vec3 lightVector = vec3(ex_worldPosition) - ex_worldLight;
	vec3 viewVector = - vec3(ex_worldPosition);
	vec3 reflectVector = reflect(lightVector,ex_worldNormal);

	vec4 ambient = getAmbient();
	vec4 diffuse = getDiffuse(lightVector);
	vec4 specular = getSpecular(viewVector, reflectVector);

	//frag_colour = vec4( 1, 1, 1, 1.0);
	//frag_colour = getAmbient() + getDiffuse(lightVector) + getSpecular(viewVector, reflectVector);
	frag_colour = texture(textureUnitID, uv);
}
