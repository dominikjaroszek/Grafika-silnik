#pragma once
/// Klasa dla animowanych obiektów gry
///
/// Klasa bazowa dla wszystkich obiektów gry, które mog¹ byæ w pewien sposób animowane
class AnimatedObject
{
public:
	/// Wirtualna metoda odpowiedzialna za animowanie obiektu.
	///
	/// Metoda animate() jest wirtualn¹ funkcj¹, która powinna zostaæ zaimplementowana przez klasy dziedzicz¹ce po AnimatedObject.
	virtual void animate()=0;
};

