#version 150

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat4 normalMatrix; 

uniform vec3 lightPos;
 
in vec4 position;
in vec4 color;
in vec3 normal;
in vec2 texcoord;

out vec4 vertColor;
out vec3 ecNormal;
out vec3 lightDir;
out vec4 vertTexCoord;
out vec2 vUv;

void main() {

	
	vec3 ecVertex = vec3(modelViewMatrix * position);
	mat3 normalMatrix = transpose(inverse(mat3(modelViewMatrix)));
	ecNormal = normalize(normalMatrix * normal);
	vertColor = color;
	lightDir = normalize(lightPos - ecVertex);
	vec4 vertTexCoord = textureMatrix * vec4(texcoord, 1.0, 1.0);
	vUv = texcoord;
	//gl_Position = projectionMatrix * modelViewMatrix * position;
 	gl_Position = modelViewProjectionMatrix * position;

}