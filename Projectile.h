#pragma once
#include "UpdatableObject.h"
class Projectile : public UpdatableObject
{
public:
	Projectile();
	/// Konstruktor klasy Projectile.
	///
	/// @param window Referencja do obiektu sf::RenderWindow, w kt�rym obiekt b�dzie renderowany.
	/// @param position Pocz�tkowa pozycja obiektu.
	/// @param direction Kierunek ruchu obiektu (np. lewo, prawo).
	/// @param moving Okre�la, czy obiekt jest w ruchu.

	Projectile(sf::RenderWindow& window, sf::Vector2f position, int direction, bool moving);
	/// Metoda aktualizuj�ca stan obiektu Projectile.
	/// Metoda rysuje obiekt na oknie, aktualizuje jego pozycj� zgodnie z kierunkiem ruchu 
	void update();
	///Metoda sprawdzaj�ca miejsce obiektu
	///
	/// Metoda zwraca warto�� true, je�li obiekt opu�ci� obszar gry (przekroczy� granice okna lub dotar� do dolnej kraw�dzi ekranu),
	/// @return True, je�li obiekt przekroczy� obszar, False w przeciwnym razie.
	bool projectableReady();

	sf::Sprite getSprite();
	

private:
	/// Obiekt sf::Sprite reprezentuj�cy element graficzny obiektu.
	sf::Sprite sprite;
	/// Referencja do obiektu sf::RenderWindow, w kt�rym obiekt jest renderowany.
	sf::RenderWindow& window;
	/// Obiekt sf::Texture przechowuj�cy tekstur� obiektu.
	sf::Texture texture;
	/// Zmienna przechowuj�ca informacj� o kierunku ruchu obiektu (1 lub -1).
	int direction;
	/// Pr�dko�� poziomego ruchu obiektu.
	float speedHorizontal;
	/// Pr�dko�� pionowego ruchu obiektu.
	float speedVertical;
	/// Wsp�czynnik zmniejszania pr�dko�ci pionowego ruchu.
	float decreaseVerticalSpeed;
	

};

