#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	float getZNoiseValue(int _x, int _y, float n1_freq, float n2_freq, float n1_amp, float n2_amp);


	float xoff, yoff;
	int cols, rows;
	int terrainW, terrainH;
	int scl;




	ofMesh mesh;

	bool showIndices;

	float terrainZPos;
	float terrainZPosOff;

	//light
	ofLight light;

	bool over = false;
	ofCamera myCamera;

};