#include "ofxFaceMesher.h"
#include "IFaceModifier.h"
#include "IMeshModifier.h"
#include "ofApp.h"


ofxFaceMesher::ofxFaceMesher()
	: showWireframe(0)
{
}


ofxFaceMesher::~ofxFaceMesher()
{
}

void ofxFaceMesher::draw()
{
	switch (showWireframe) {
		case 0:
			obj.draw(); break;
		case 1:
			obj.draw();
			obj.drawNormals(25.f);
			break;
		case 2:
			obj.drawWireframe(); break;
		default:
			obj.drawVertices(); break;
	}
	

}

void ofxFaceMesher::regenerateMesh()
{
	ofMesh& mesh = obj.getMesh();
	mesh.setMode(OF_PRIMITIVE_TRIANGLES);
	mesh.clear();
	int count = 0;
	for (const auto& face : faces) {
		mesh.addVertices(&(face.points[0]), 4);
		mesh.addIndex(count);
		mesh.addIndex(count + 1);
		mesh.addIndex(count + 2);
		mesh.addIndex(count + 2);
		mesh.addIndex(count + 3);
		mesh.addIndex(count + 0);
		mesh.addNormal(face.normal);
		mesh.addNormal(face.normal);
		mesh.addNormal(face.normal);
		mesh.addNormal(face.normal);
		count += 4;
	}
}

void ofxFaceMesher::modify(const IFaceModifier* modifier, size_t index)
{
	modifier->modify(faces[index]);
}

void ofxFaceMesher::modify(const IMeshModifier* modifier) 
{
	modifier->modify(faces);
}
