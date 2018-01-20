#include "ofApp.h"
#include "BaseUnitModifier.h"

Modifier mesh(IMeshModifier* modifier) {
	ModifierPtr mod;
	mod.mesh = modifier;
	return{ true, mod };
}

//--------------------------------------------------------------
void ofApp::setup(){
	cam.enableOrtho();
	cam.setTarget({ 0,0,0 });
	cam.setPosition({ 200, 200, 200 });
	light.setup();
	light.setPosition(200, 200, 50);
	material.setDiffuseColor(ofFloatColor::red);
	material.setShininess(0.02);
	ofEnableDepthTest();
	ofEnableLighting();
	modifiers.push_back(mesh(BaseUnitModifier::baseVolumne116()));
	glPointSize(5.0f);
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
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::beige);
	cam.begin();
	  material.begin();
	    mesher.draw();
	  material.end();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	mesher.showWireframe = (mesher.showWireframe + 1) % 3;
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
