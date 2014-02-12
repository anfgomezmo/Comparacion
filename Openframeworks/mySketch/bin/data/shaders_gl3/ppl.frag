#version 150


uniform sampler2DRect tex0;

in vec4 vertColor;
in vec3 ecNormal;
in vec3 lightDir;
in vec2 vUv;
in vec4 vertTexCoord;
out vec4 outputColor;


void main(){ 

	vec3 direction = normalize(lightDir);
	vec3 normal1 = normalize(ecNormal);
	float intensity = max(0.0, dot(direction, normal1));
	vec4 tintColor = vec4(intensity, intensity, intensity, 1.0) * vertTexCoord;
	vec4 texture1 = texture(tex0, vUv);
	outputColor = vec4(texture1 * tintColor);  	  
	//outputColor = vec4(texture1);

}