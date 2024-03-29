#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/// Klasa reprezentująca wroga w grze.
///
/// Klasa Enemy odpowiada za reprezentację i aktualizację stanu wroga w grze.
class Enemy
{
public:
	/// Konstruktor klasy Enemy.
	/// 
	/// @param window Referencja do obiektu sf::RenderWindow, na którym wrogowie są renderowani.
	/// @param position Początkowa pozycja wroga.
	/// @param type Typ wroga, determinujący wygląd.
	Enemy(sf::RenderWindow& window, sf::Vector2f position, std::string type);
	/// Metoda aktualizująca stan wroga.
	///
	/// Metoda update() jest odpowiedzialna za aktualizację stanu wroga, np. jego pozycji czy wyglądu.
	void update();
	/// Metoda zwracająca pozycję wroga.
	///
	/// @return Obiekt sf::Vector2f reprezentujący aktualną pozycję wroga.
	sf::Vector2f getPosition();
	/// Metoda zwracająca sprite przeciwnika.
	sf::Sprite getSprite();


private:
	/// Referencja do obiektu sf::RenderWindow, na którym wrogowie są renderowani.
	sf::RenderWindow& window;
	/// Obiekt sf::Sprite reprezentujący wroga.
	sf::Sprite sprite;
	/// Obiekt sf::Texture przechowujący teksturę wroga.
	sf::Texture texture;
};

