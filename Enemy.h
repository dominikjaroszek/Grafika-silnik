#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/// Klasa reprezentuj¹ca wroga w grze.
///
/// Klasa Enemy odpowiada za reprezentacjê i aktualizacjê stanu wroga w grze.
class Enemy
{
public:
	/// Konstruktor klasy Enemy.
	/// 
	/// @param window Referencja do obiektu sf::RenderWindow, na którym wrogowie s¹ renderowani.
	/// @param position Pocz¹tkowa pozycja wroga.
	/// @param type Typ wroga, determinuj¹cy wygl¹d.
	Enemy(sf::RenderWindow& window, sf::Vector2f position, std::string type);
	/// Metoda aktualizuj¹ca stan wroga.
	///
	/// Metoda update() jest odpowiedzialna za aktualizacjê stanu wroga, np. jego pozycji czy wygl¹du.
	void update();
	/// Metoda zwracaj¹ca pozycjê wroga.
	///
	/// @return Obiekt sf::Vector2f reprezentuj¹cy aktualn¹ pozycjê wroga.
	sf::Vector2f getPosition();
	/// Metoda zwracaj¹ca sprite przeciwnika.
	sf::Sprite getSprite();


private:
	/// Referencja do obiektu sf::RenderWindow, na którym wrogowie s¹ renderowani.
	sf::RenderWindow& window;
	/// Obiekt sf::Sprite reprezentuj¹cy wroga.
	sf::Sprite sprite;
	/// Obiekt sf::Texture przechowuj¹cy teksturê wroga.
	sf::Texture texture;
};

