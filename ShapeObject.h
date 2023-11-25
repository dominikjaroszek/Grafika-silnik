#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"
/// Klasa reprezentuj�ca abstrakcyjny kszta�t, kt�ry mo�na transformowa� i rysowa�.
///
/// Klasa ShapeObject dziedziczy jednocze�nie po klasach TransformableObject i DrawableObject. Oznacza to, �e obiekty tej klasy mog� by� poddawane r�nym transformacjom oraz mog� by� rysowane na ekranie.
class ShapeObject : public TransformableObject, public DrawableObject
{
	virtual void draw();
	virtual void translate();
	virtual void rotate();
	virtual void scale();
};

