#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(10, 10, 10);
	ofEnableDepthTest();
	img.loadImage("lachoy.jpg");	
	cylinder.set( 100, 200 );
	cylinder.setResolution(32, 32, 2);
	//ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setPosition(512,50,300);
	pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
	cylinder.mapTexCoordsFromTexture(img.getTextureReference()); 
	//shader.load("shaders/ppl.vert", "shaders/ppl.frag");
	shader.load("shaders/ppl.vert", "shaders/ppl.frag");

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	img.getTextureReference().bind();
	ofEnableLighting();
    pointLight.enable();

	shader.begin();
	
	cylinder.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
	cylinder.rotate(0.1, 0, 1.0, 0.0);
	ofVec3f lightPos = pointLight.getPosition();
	shader.setUniform3f("lightPos", lightPos.x, lightPos.y, lightPos.z);
	//shader.setUniformTexture("texturein", texture.getTextureReference(), 1);
	cylinder.draw();
    
	shader.end();
	//cylinder.draw();
	
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
