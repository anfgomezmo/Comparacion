#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 normalMatrix;
uniform mat4 textureMatrix;

uniform vec3 lightPosition;
 
in vec4 position;
in vec4 color;
in vec3 normal;
in vec2 texcoord;

out vec4 vertColor;
out vec4 vertTexCoord;

void main() {
  //mat3 normalMatrix = transpose(inverse(mat3(modelViewMatrix)));

  gl_Position = modelViewProjectionMatrix * position;
  vec3 ecVertex = vec3(modelViewMatrix * position);  
  vec3 ecNormal = normalize(normalMatrix * vec4(normal, 1)).xyz;

  vec3 direction = normalize(lightPosition.xyz - ecVertex);    
  float intensity = max(0.0, dot(direction, ecNormal));
  //vertColor = vec4(intensity, intensity, intensity, 1) * color;     
  vertColor = vec4(intensity, intensity, intensity, 1) * vec4(1, 1, 1, 1);
  //vertColor = vec4(direction, 1);
  
  vertTexCoord = textureMatrix * vec4(texcoord, 1.0, 1.0);  
}