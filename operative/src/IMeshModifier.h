#pragma once

#include <vector>
#include "face.h"

using Mesh = std::vector<Face>;

class IMeshModifier {
public:
	virtual ~IMeshModifier() = default;
	virtual void modify(Mesh& mesh) const = 0;
};