#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/// Klasa reprezentuj�ca wroga w grze.
///
/// Klasa Enemy odpowiada za reprezentacj� i aktualizacj� stanu wroga w grze.
class Enemy
{
public:
	/// Konstruktor klasy Enemy.
	/// 
	/// @param window Referencja do obiektu sf::RenderWindow, na kt�rym wrogowie s� renderowani.
	/// @param position Pocz�tkowa pozycja wroga.
	/// @param type Typ wroga, determinuj�cy wygl�d.
	Enemy(sf::RenderWindow& window, sf::Vector2f position, std::string type);
	/// Metoda aktualizuj�ca stan wroga.
	///
	/// Metoda update() jest odpowiedzialna za aktualizacj� stanu wroga, np. jego pozycji czy wygl�du.
	void update();
	/// Metoda zwracaj�ca pozycj� wroga.
	///
	/// @return Obiekt sf::Vector2f reprezentuj�cy aktualn� pozycj� wroga.
	sf::Vector2f getPosition();
	/// Metoda zwracaj�ca sprite przeciwnika.
	sf::Sprite getSprite();


private:
	/// Referencja do obiektu sf::RenderWindow, na kt�rym wrogowie s� renderowani.
	sf::RenderWindow& window;
	/// Obiekt sf::Sprite reprezentuj�cy wroga.
	sf::Sprite sprite;
	/// Obiekt sf::Texture przechowuj�cy tekstur� wroga.
	sf::Texture texture;
};

