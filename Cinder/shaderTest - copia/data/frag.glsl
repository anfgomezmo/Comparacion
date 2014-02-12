#version 120

uniform sampler2D tex0;
varying vec2 texCoordVarying;
varying vec4 vertColor;
varying vec3 ecNormal;
varying vec3 lightDir;
varying vec4 vertTexCoord;



void main()
{
	
	vec3 direction = normalize(lightDir);
   vec3 normal = normalize(ecNormal);
   float intensity = max(0.0, dot(direction, normal));
   vec4 tintColor = vec4(intensity, intensity, intensity, 1.0)* vertColor;
	gl_FragColor.rgb = texture2D( tex0, gl_TexCoord[0].st ).rgb * tintColor ;
	//gl_FragColor.a = 1.0;
}