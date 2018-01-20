#pragma once

#include "face.h"

class IFaceModifier {
public:
	virtual ~IFaceModifier() = default;
	virtual void modify(Face& face) const = 0;
};