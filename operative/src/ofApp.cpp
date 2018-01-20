#include "ofApp.h"
#include "BaseUnitModifier.h"
#include "Expand.h"

const float ROLL_VALUE = -15.f;
const float TILT_VALUE = -30.f;
const float PAN_VALUE = -30.f;
const float X_VALUE = -70.f;
const float Y_VALUE = 150.f;
const float Z_VALUE = 190.f;

Modifier mesh(IMeshModifier* modifier) {
	ModifierPtr mod;
	mod.mesh = modifier;
	return{ true, mod };
}

Modifier face(IFaceModifier* modifier) {
	ModifierPtr mod;
	mod.face = modifier;
	return{ false, mod };
}

//--------------------------------------------------------------
void ofApp::setup(){
	cam.enableOrtho();
	x = X_VALUE;
	y = Y_VALUE;
	z = Z_VALUE;
	cam.setPosition({ x, y, z });
	cam.roll(ROLL_VALUE);
	cam.tilt(TILT_VALUE);
	cam.pan(PAN_VALUE);
	light.setup();
	light.setPosition(200, 200, 50);
	crossLight.setup();
	crossLight.setPosition(-200, -200, 50);
	crossLight.setDiffuseColor({ 0.25, 0.25, 0.25 });
	ambient.setup();
	ambient.setAmbientColor({ 0.50, 0.50, 0.50 });
	ofSetSmoothLighting(true);
	material.setDiffuseColor(ofFloatColor::red);
	material.setShininess(0.02);
	ofEnableDepthTest();
	ofEnableLighting();
	modifiers.push_back(mesh(BaseUnitModifier::baseVolume14()));
	//modifiers.push_back(mesh(new Expand()));
	glPointSize(5.0f);
	glEnable(GL_CULL_FACE);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (const Modifier& mod : modifiers) {
		if (mod.isMeshModifier) {
			mesher.modify(mod.modifier.mesh);
		}
		else {
			mesher.modify(mod.modifier.face, 0); // TODO: Randomly pick a face
		}
	}
	mesher.regenerateMesh();
	cam.setPosition(x, y, z);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::beige);
	
	cam.begin();
	light.enable(); ambient.disable(); crossLight.enable();
	  material.begin();
	    mesher.draw();
	  material.end();
	  light.draw(); crossLight.draw();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key) {
	case ' ':
		mesher.showWireframe = (mesher.showWireframe + 1) % 4; break;
	//case OF_KEY_UP:
	//	y += 10.f; break;
	//case OF_KEY_DOWN:
	//	y -= 10.f; break;
	//case OF_KEY_LEFT:
	//	x += 10.f; break;
	//case OF_KEY_RIGHT:
	//	x -= 10.f; break;
	//case OF_KEY_PAGE_DOWN:
	//	z -= 10.f; break;
	//case OF_KEY_PAGE_UP:
	//	z += 10.f; break;
	case OF_KEY_RETURN:
		grab.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		grab.save("screenshot.png");
	//	ofLog() << "X: " << x;
	//	ofLog() << "Y: " << y;
	//	ofLog() << "Z: " << z;
		break;
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
