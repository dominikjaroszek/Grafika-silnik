#pragma once
#include "GameObject.h"

/// Klasa reprezentuj¹ca obiekt rysowalny.
///
/// Klasa DrawableObject dziedziczy po klasie GameObject i deklaruje jedn¹ wirtualn¹ metodê draw().
class DrawableObject : public GameObject
{
	/// Wirtualna metoda odpowiedzialna za rysowanie obiektu.
	///
	/// Metoda draw() jest wirtualn¹ funkcj¹, która powinna zostaæ zaimplementowana przez klasy dziedzicz¹ce po DrawableObject.
	virtual void draw();
};

