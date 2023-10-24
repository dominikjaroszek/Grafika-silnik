#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"
class ShapeObject : public TransformableObject, public DrawableObject
{
	virtual void draw();
	virtual void translate();
	virtual void rotate();
	virtual void scale();
};

