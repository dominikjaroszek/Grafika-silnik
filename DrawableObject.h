#pragma once
#include "GameObject.h"

/// Klasa reprezentuj�ca obiekt rysowalny.
///
/// Klasa DrawableObject dziedziczy po klasie GameObject i deklaruje jedn� wirtualn� metod� draw().
class DrawableObject : public GameObject
{
	/// Wirtualna metoda odpowiedzialna za rysowanie obiektu.
	///
	/// Metoda draw() jest wirtualn� funkcj�, kt�ra powinna zosta� zaimplementowana przez klasy dziedzicz�ce po DrawableObject.
	virtual void draw();
};

