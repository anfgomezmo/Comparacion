#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void updateLights();
		void updateNormalMatrix();
		ofMatrix3x3 mat4ToMat3(ofMatrix4x4 mat4);
		ofMatrix4x4 mat3ToMat4(ofMatrix3x3 mat3);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		float angle;
		ofCylinderPrimitive cylinder;
		ofImage label;
		ofLight pointLight;
		ofShader shader;
};
