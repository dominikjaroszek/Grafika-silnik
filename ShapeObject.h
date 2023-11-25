#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"
/// Klasa reprezentuj¹ca abstrakcyjny kszta³t, który mo¿na transformowaæ i rysowaæ.
///
/// Klasa ShapeObject dziedziczy jednoczeœnie po klasach TransformableObject i DrawableObject. Oznacza to, ¿e obiekty tej klasy mog¹ byæ poddawane ró¿nym transformacjom oraz mog¹ byæ rysowane na ekranie.
class ShapeObject : public TransformableObject, public DrawableObject
{
	/// Wirtualna metoda odpowiedzialna za rysowanie obiektu.
	///
	/// Metoda draw() jest wirtualn¹ funkcj¹, która powinna zostaæ zaimplementowana przez klasy dziedzicz¹ce po ShapeObject.
	virtual void draw();
	/// Wirtualna metoda przemieszczaj¹ca obiekt.
	///
	/// Metoda translate() jest wirtualn¹ funkcj¹, która powinna zostaæ zaimplementowana przez klasy dziedzicz¹ce po ShapeObject.
	virtual void translate();
	/// Wirtualna metoda obracaj¹ca obiekt.
	///
	/// Metoda rotate() jest wirtualn¹ funkcj¹, która powinna zostaæ zaimplementowana przez klasy dziedzicz¹ce po ShapeObject.
	virtual void rotate();
	/// Wirtualna metoda skaluj¹ca obiekt.
	///
	/// Metoda scale() jest wirtualn¹ funkcj¹, która powinna zostaæ zaimplementowana przez klasy dziedzicz¹ce po ShapeObject.
	virtual void scale();
};

