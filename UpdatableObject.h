#pragma once
#include "GameObject.h"

/// Klasa abstrakcyjna reprezentuj�ca obiekt gry podlegaj�cy aktualizacji.
///
/// Klasa UpdatableObject dziedziczy po klasie GameObject

class UpdatableObject : public GameObject
{
public:
	/// Wirtualna metoda do aktualizacji stanu obiektu gry.
	virtual void update() = 0;
};

