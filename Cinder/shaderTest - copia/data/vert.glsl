#version 120
uniform vec3 lightPos;

varying vec2 texCoordVarying;
varying vec4 vertColor;
varying vec3 ecNormal;
varying vec3 lightDir;
varying vec4 vertTexCoord;

void main()
{
	gl_TexCoord[0] = gl_MultiTexCoord0;
	vec3 ecVertex = vec3(gl_ModelViewMatrix * gl_Vertex);
    ecNormal = normalize(gl_NormalMatrix * gl_Normal);
    lightDir = normalize(lightPos - ecVertex);
	vertColor = gl_Color;
    vertTexCoord = gl_TextureMatrix[0] * gl_TexCoord[0];
	gl_Position =  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;;
}
