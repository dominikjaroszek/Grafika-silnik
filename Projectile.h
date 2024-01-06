#pragma once
#include "UpdatableObject.h"
class Projectile : public UpdatableObject
{
public:
	Projectile();
	/// Konstruktor klasy Projectile.
	///
	/// @param window Referencja do obiektu sf::RenderWindow, w którym obiekt bêdzie renderowany.
	/// @param position Pocz¹tkowa pozycja obiektu.
	/// @param direction Kierunek ruchu obiektu (np. lewo, prawo).
	/// @param moving Okreœla, czy obiekt jest w ruchu.

	Projectile(sf::RenderWindow& window, sf::Vector2f position, int direction, bool moving);
	/// Metoda aktualizuj¹ca stan obiektu Projectile.
	/// Metoda rysuje obiekt na oknie, aktualizuje jego pozycjê zgodnie z kierunkiem ruchu 
	void update();
	///Metoda sprawdzaj¹ca miejsce obiektu
	///
	/// Metoda zwraca wartoœæ true, jeœli obiekt opuœci³ obszar gry (przekroczy³ granice okna lub dotar³ do dolnej krawêdzi ekranu),
	/// @return True, jeœli obiekt przekroczy³ obszar, False w przeciwnym razie.
	bool projectableReady();

	sf::Sprite getSprite();
	

private:
	/// Obiekt sf::Sprite reprezentuj¹cy element graficzny obiektu.
	sf::Sprite sprite;
	/// Referencja do obiektu sf::RenderWindow, w którym obiekt jest renderowany.
	sf::RenderWindow& window;
	/// Obiekt sf::Texture przechowuj¹cy teksturê obiektu.
	sf::Texture texture;
	/// Zmienna przechowuj¹ca informacjê o kierunku ruchu obiektu (1 lub -1).
	int direction;
	/// Prêdkoœæ poziomego ruchu obiektu.
	float speedHorizontal;
	/// Prêdkoœæ pionowego ruchu obiektu.
	float speedVertical;
	/// Wspó³czynnik zmniejszania prêdkoœci pionowego ruchu.
	float decreaseVerticalSpeed;
	

};

