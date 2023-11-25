#pragma once
/// Klasa dla animowanych obiekt�w gry
///
/// Klasa bazowa dla wszystkich obiekt�w gry, kt�re mog� by� w pewien spos�b animowane
class AnimatedObject
{
public:
	/// Wirtualna metoda odpowiedzialna za animowanie obiektu.
	///
	/// Metoda animate() jest wirtualn� funkcj�, kt�ra powinna zosta� zaimplementowana przez klasy dziedzicz�ce po AnimatedObject.
	virtual void animate()=0;
};

