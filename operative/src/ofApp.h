#pragma once

#include "ofMain.h"
#include "ofxFaceMesher.h"
#include "IMeshModifier.h"

union ModifierPtr {
	IMeshModifier* mesh;
	IFaceModifier* face;
};
using Modifier = struct {
	bool isMeshModifier;
	ModifierPtr modifier;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofLight light, ambient, crossLight;
		ofCamera cam;
		ofxFaceMesher mesher;
		std::vector<Modifier> modifiers;
		ofMaterial material;
		float x,y,z;
		ofImage grab;
};
