#pragma once
#include "GameObject.h"
class TransformableObject : public GameObject
{
    virtual void translate(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void scale(float factor) = 0;
};

