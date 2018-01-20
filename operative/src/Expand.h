#pragma once

#include "IMeshModifier.h"

class Expand : public IMeshModifier {
public:
	virtual void modify(Mesh& mesh) const override {
		mesh[0].points[1].x += 25.f;
		mesh[0].points[2].x += 25.f;
		mesh[1].points[1].x += 25.f;
		mesh[3].points[1].x += 25.f;
		mesh[4].points[0].x += 25.f;
		mesh[4].points[1].x += 25.f;
	}
};
