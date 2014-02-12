#version 120

// this is coming from our C++ code

uniform vec3 lightPos;

varying vec2 texCoordVarying;
varying vec4 vertColor;
varying vec3 ecNormal;
varying vec3 lightDir;
varying vec4 vertTexCoord;

void main()
{
    vec2 texcoord = gl_MultiTexCoord0.xy;
    vec3 ecVertex = vec3(gl_ModelViewMatrix * gl_Vertex);
    ecNormal = normalize(gl_NormalMatrix * gl_Normal);
    lightDir = normalize(lightPos - ecVertex);
    vertColor = gl_Color;
    // here we move the texture coordinates
    texCoordVarying = vec2(texcoord.x, texcoord.y);
    vertTexCoord = gl_TextureMatrix[0] * vec4(texcoord, 1.0, 1.0);
    // send the vertices to the fragment shader
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;;

}