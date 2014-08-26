// Texture from Jason Liebig's FLICKR collection of vintage labels and wrappers:
// http://www.flickr.com/photos/jasonliebigstuff/3739263136/in/photostream/

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0);
	ofEnableDepthTest();

    pointLight.setDiffuseColor(ofFloatColor(0, 0, 0));
    pointLight.setPosition(ofGetWidth()/2, ofGetHeight(), 200);
	pointLight.setSpecularColor(ofFloatColor(1, 1, 1));

	label.loadImage("lachoy.jpg");
	cylinder.set( 100, 200 );
	cylinder.setResolution(32, 32, 2);
	cylinder.mapTexCoordsFromTexture(label.getTextureReference()); 
	shader.load("vert.glsl", "frag.glsl");
}

//--------------------------------------------------------------
void testApp::update(){
	angle += 0.01;
}

//--------------------------------------------------------------
void testApp::draw(){
	shader.begin();
    updateLights();

	ofPushMatrix();

	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
	ofRotateY(360 * (0.01 / TWO_PI));

	//cylinder.rotate(360 * (0.01 / TWO_PI), 0, 1, 0);
	updateNormalMatrix();

	label.bind();
	cylinder.draw();
	label.unbind();

	ofPopMatrix();

	shader.end();
}

void testApp::updateLights() {
  ofMatrix4x4 modelViewMatrix = ofGetCurrentMatrix(OF_MATRIX_MODELVIEW);
  ofVec3f cameraSpaceLightPos = pointLight.getPosition() * modelViewMatrix;
  shader.setUniform3f("lightPosition", cameraSpaceLightPos.x, cameraSpaceLightPos.y, cameraSpaceLightPos.z);
}

void testApp::updateNormalMatrix() {
  ofMatrix4x4 modelViewMatrix = ofGetCurrentMatrix(OF_MATRIX_MODELVIEW);
  ofMatrix3x3 normalMatrix3 = mat4ToMat3(modelViewMatrix);
  normalMatrix3.invert();
  normalMatrix3.transpose();
  ofMatrix4x4 normalMatrix4 = mat3ToMat4(normalMatrix3);
  shader.setUniformMatrix4f("normalMatrix", normalMatrix4);
}

ofMatrix3x3 testApp::mat4ToMat3(ofMatrix4x4 mat4) {
  return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], 
	                 mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], 
					 mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}

ofMatrix4x4 testApp::mat3ToMat4(ofMatrix3x3 mat3)
{
  return ofMatrix4x4(mat3.a, mat3.b, mat3.c, 0,
	                 mat3.d, mat3.e, mat3.f, 0, 
					 mat3.g, mat3.h, mat3.i, 0,
					      0,      0,      0, 1);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
