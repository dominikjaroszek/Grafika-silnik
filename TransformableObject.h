#pragma once
#include "DrawableObject.h"
class TransformableObject : public GameObject
{
	virtual void translate();
	virtual void rotate();
	virtual void scale();
};

