#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"
/// Klasa reprezentuj¹ca abstrakcyjny kszta³t, który mo¿na transformowaæ i rysowaæ.
///
/// Klasa ShapeObject dziedziczy jednoczeœnie po klasach TransformableObject i DrawableObject. Oznacza to, ¿e obiekty tej klasy mog¹ byæ poddawane ró¿nym transformacjom oraz mog¹ byæ rysowane na ekranie.
class ShapeObject : public TransformableObject, public DrawableObject
{
	virtual void draw();
	virtual void translate();
	virtual void rotate();
	virtual void scale();
};

