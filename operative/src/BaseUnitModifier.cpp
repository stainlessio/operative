#include "BaseUnitModifier.h"

void BaseUnitModifier::modify(Mesh& mesh) const {
	mesh.clear();
	mesh.reserve(6);  // Base unit has 6 faces
	Face face = make_face({ 0, h, 0 }, { w, h, 0 }, { w, 0, 0 }, { 0,0,0 }, INTO);
	mesh.push_back(face);
	face = make_face({ 0,0,0 }, { w, 0, 0 }, { w, 0, d }, { 0, 0, d }, DOWN);
	mesh.push_back(face);
	face = make_face({ 0,0,d }, { 0,h,d }, { 0,h,0 }, { 0,0,0 }, LEFT);
	mesh.push_back(face);
	face = make_face({ w,h,d }, { w,h,0 }, { 0,h,0 }, { 0,h,d }, UP);
	mesh.push_back(face);
	face = make_face({ w,0,0 }, { w,h,0 }, { w,h,d }, { w,0,d }, RIGHT);
	mesh.push_back(face);
	face = make_face({ 0,0,d }, { w,0,d }, { w,h,d }, { 0,h,d }, OUTOF);
	mesh.push_back(face);
}