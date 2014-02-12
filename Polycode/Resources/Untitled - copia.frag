varying vec3 normal;
varying vec4 pos;
varying vec4 vertexColor;

uniform sampler2D diffuse;
uniform vec4 diffuse_color;
uniform vec4 specular_color;
uniform vec4 ambient_color;
uniform float shininess;



void pointLight(in int i, in vec3 normal, in vec4 pos, inout vec4 diffuse, inout vec4 specular) {
vec4 color = diffuse_color;
vec4 matspec = specular_color;
float shininess = shininess;
vec4 lightspec = gl_LightSource[i].specular;
vec4 lpos = gl_LightSource[i].position;
vec4 s = lpos-pos;
vec4 sn = normalize(s);

vec3 light = sn.xyz;
vec3 n = normalize(normal);
vec3 r = reflect(light, n);
r = normalize(r);
vec3 v = pos.xyz;
v = normalize(v);

float nDotL = dot(light, n);


diffuse += color* max(0.0, nDotL) ;




}



void doLights(in int numLights, in vec3 normal, in vec4 pos, inout vec4 diffuse, inout vec4 specular) {
for (int i = 0; i < numLights; i++) {
if (gl_LightSource[i].spotCutoff == 180.0) {
pointLight(i, normal, pos, diffuse, specular);
} else {
//spotLight(i, normal, pos, diffuse, specular);
}
    }
}


void main()
{
vec4 diffuse_val = vec4(0.0);
vec4 specular_val = vec4(0.0);
doLights(1, normal, pos, diffuse_val, specular_val);

vec4 texColor = texture2D(diffuse, gl_TexCoord[0].st);	

    vec4 color = diffuse_val + ambient_color;
    color = clamp((color*vertexColor*texColor) + specular_val, 0.0, 1.0);

gl_FragColor = color;

}