#pragma once
#include "GameObject.h"

/// Klasa abstrakcyjna reprezentuj¹ca obiekt gry podlegaj¹cy aktualizacji.
///
/// Klasa UpdatableObject dziedziczy po klasie GameObject

class UpdatableObject : public GameObject
{
public:
	/// Wirtualna metoda do aktualizacji stanu obiektu gry.
	virtual void update() = 0;
};

