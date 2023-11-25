#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"
/// Klasa reprezentuj�ca abstrakcyjny kszta�t, kt�ry mo�na transformowa� i rysowa�.
///
/// Klasa ShapeObject dziedziczy jednocze�nie po klasach TransformableObject i DrawableObject. Oznacza to, �e obiekty tej klasy mog� by� poddawane r�nym transformacjom oraz mog� by� rysowane na ekranie.
class ShapeObject : public TransformableObject, public DrawableObject
{
	/// Wirtualna metoda odpowiedzialna za rysowanie obiektu.
	///
	/// Metoda draw() jest wirtualn� funkcj�, kt�ra powinna zosta� zaimplementowana przez klasy dziedzicz�ce po ShapeObject.
	virtual void draw();
	/// Wirtualna metoda przemieszczaj�ca obiekt.
	///
	/// Metoda translate() jest wirtualn� funkcj�, kt�ra powinna zosta� zaimplementowana przez klasy dziedzicz�ce po ShapeObject.
	virtual void translate();
	/// Wirtualna metoda obracaj�ca obiekt.
	///
	/// Metoda rotate() jest wirtualn� funkcj�, kt�ra powinna zosta� zaimplementowana przez klasy dziedzicz�ce po ShapeObject.
	virtual void rotate();
	/// Wirtualna metoda skaluj�ca obiekt.
	///
	/// Metoda scale() jest wirtualn� funkcj�, kt�ra powinna zosta� zaimplementowana przez klasy dziedzicz�ce po ShapeObject.
	virtual void scale();
};

