#pragma once

#include <vector>
#include "ofMain.h"
#include "face.h"

class IFaceModifier;
class IMeshModifier;

class ofxFaceMesher
{
public:
	ofxFaceMesher();
	virtual ~ofxFaceMesher();

	void draw();
	void regenerateMesh();
	void modify(const IFaceModifier* modifier, size_t index);
	void modify(const IMeshModifier* modifier);

	std::vector<Face> faces;
	ofMesh mesh;
	int showWireframe;
};

