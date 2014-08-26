#version 150

uniform sampler2DRect tex0;

in vec4 vertColor;
in vec4 vertTexCoord;

out vec4 outputColor;

void main() {
  outputColor = texture(tex0, vertTexCoord.st) * vertColor;
}
