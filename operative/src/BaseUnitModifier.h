#include "ofMain.h"
#include "face.h"
#include "IMeshModifier.h"

const ofVec3f UP{ 0, 5, 0 };
const ofVec3f DOWN{ 0, -5, 0 };
const ofVec3f LEFT{ -5, 0, 0 };
const ofVec3f RIGHT{ 5, 0, 0 };
const ofVec3f INTO{ 0, 0, -5 };
const ofVec3f OUTOF{ 0, 0, 5 };


class BaseUnitModifier : public IMeshModifier {
public:
	BaseUnitModifier(float w, float h, float d) :
		w(w), h(h), d(d) {

	}

	virtual ~BaseUnitModifier() = default;

	void modify(Mesh& mesh) const override;

	float w, h, d;

	static BaseUnitModifier* baseVolume11() {
		return new BaseUnitModifier { 100, 100, 100 };
	}

	static BaseUnitModifier* baseVolume12() {
		return new BaseUnitModifier { 50, 100, 100 };
	}

	static BaseUnitModifier* baseVolume14() {
		return new BaseUnitModifier { 50, 50, 100 };
	}

	static BaseUnitModifier* baseVolume18() {
		return new BaseUnitModifier { 50, 50, 50 };
	}

	static BaseUnitModifier* baseVolume116() {
		return new BaseUnitModifier { 25, 25, 100 };
	}

private:
	inline Face make_face(ofVec3f p1, ofVec3f p2, ofVec3f p3, ofVec3f p4, ofVec3f normal) const {
		return{
			{p1, p2, p3, p4},
			normal
		};
	}
};