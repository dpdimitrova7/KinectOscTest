#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofEnableDepthTest();
	ofDisableArbTex();
/*
	if (ofGetMouseY() < 5 && ofGetMouseY() > -5) {
		over = true;
     std::cout << "mouse is between" << endl;
	}
	else if(ofGetMouseY()>50 && ofGetMouseY() <-50){
		over = false;
		
	}
	*/
	/*
		myCamera.setGlobalPosition(410, 
			ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 1000),
			ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 1000));
			*/

	myCamera.setGlobalPosition(410, 0, 0);
			
		/*
		
	
if(!over){
		myCamera.setGlobalPosition(410, 130, 30);
	}
*/
	//myCamera.lookAt({ 0,0,0 }, { 0,0,1 });
	//myCamera.lookAt(centerPos);
	myCamera.tiltRad(1.6);
	scl = 10; // Set Scale of grids

	terrainW = 800;
	terrainH = 600;


	cols = terrainW / scl; // set rows per scl
	rows = terrainH / scl; // set columns per scl


	cout << "columns numbers: " << cols << endl;
	cout << "rows numbers: " << cols << endl;

	//mesh.setMode(OF_PRIMITIVE_POINTS);
   mesh.setMode(OF_PRIMITIVE_TRIANGLES);


	for (int j = 0; j < rows; j++) {
		xoff = 0;
		for (int i = 0; i < cols; i++) {

			float x = i * scl;
			float y = j * scl;
			//float z = ofRandom(-10,10);
			float z = ofMap(ofNoise(yoff, xoff), 0, 1, -50, 50);
			mesh.addVertex(ofVec3f(x, y, z));
			mesh.addColor(ofFloatColor(0.1, 0.3,1.2));
			mesh.addColor(ofFloatColor(ofMap(z,50,50,0,1),ofMap(z,-135,55,0,1),ofMap(z,-150,76,0,1),1));

			xoff += 0.1;
		}
		yoff += 0.1;
	}


	// Generate order of indices to set triangles per rows and column
	for (int j = 0; j < rows - 1; j++) {
		for (int i = 0; i < cols - 1; i++) {

			mesh.addIndex(i + j * cols);         // 0
			mesh.addIndex((i + 1) + j * cols);     // 1
			mesh.addIndex(i + (j + 1)*cols);     // 6

			mesh.addIndex((i + 1) + j * cols);     // 1
			mesh.addIndex((i + 1) + (j + 1)*cols); // 7
			mesh.addIndex(i + (j + 1)*cols);     // 6
		}
	}


}

float ofApp::getZNoiseValue(int _x, int _y, float n1_freq, float n2_freq, float n1_amp, float n2_amp) {

	int x = _x;
	int y = _y + ofGetFrameNum();
	float n1 = ofNoise(x * n1_freq, y * n1_freq) * n1_amp;
	float n2 = ofNoise(x * n2_freq, y * n2_freq) * n2_amp;
	float ret = n1 + n2;
	return ret;
}
//--------------------------------------------------------------
void ofApp::update() {
	light.setPosition(ofVec3f(0,sin(ofGetElapsedTimef())*100,0));
	for (int i = 0; i < mesh.getNumVertices(); i++) {
		ofVec3f vec;
		vec = mesh.getVertex(i);
		vec.z = getZNoiseValue(vec.x, vec.y, 0.02, 0.02, 0.5, 10);
		mesh.setVertex(i, vec);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackgroundGradient(ofColor(40, 40, 40), ofColor(0, 0, 0), OF_GRADIENT_CIRCULAR);

	ofPushMatrix();
	ofTranslate(ofGetWidth() - terrainW  + scl , ofGetHeight()*0.5 - terrainH * 0.5 + scl * 0.5);
	//ofRotateX(60);
	myCamera.begin();

	//ofTranslate(0, -terrainH*0.5);
	/*
	for (int j = 0; j < rows; j++) {
		xoff = 0;
		for (int i = 0 ; i < cols; i++) {
			float z = ofMap(ofNoise(xoff, yoff),0,1,-1*terrainZPos,terrainZPos);
			mesh.setVertex(i+j*cols, ofVec3f(mesh.getVertex(i+j*cols).x,mesh.getVertex(i+j*cols).y,z));
			xoff += 0.1;
		}
		yoff += 0.1;
	}*/


	ofEnableLighting();
	light.enable();
//	mesh.draw();

	light.disable();
	ofDisableLighting();

	ofSetColor(255);
	ofRotateX(ofMap(ofGetMouseY(), 0, ofGetHeight(), 389, 330));
	ofTranslate(0, ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 100), 0);
	mesh.draw();
	light.disable();
	ofDisableLighting();
	if (showIndices) {
		for (int j = 0; j < rows; j++) {
			for (int i = 0; i < cols; i++) {
				ofDrawBitmapStringHighlight(ofToString(i + j * cols), ofPoint(mesh.getVertex(i + j * cols).x - 10, mesh.getVertex(i + j * cols).y + 5));
			}
		}
	}
	ofPopMatrix();
	ofSetColor(0, 30, 140);
	
	
	myCamera.end();
	ofDrawRectangle(-500, ofGetMouseY()-100, ofGetWidth()+500, ofGetHeight()+100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == 'i') {
		showIndices = !showIndices;
	}
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
