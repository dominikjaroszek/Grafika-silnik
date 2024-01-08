#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/// Klasa reprezentuj�ca wi�nie w grze.
///
/// Klasa Cherry odpowiada za reprezentacj� i aktualizacj� stanu wi�ni w grze.
class Cherry
{
public:
	/// Konstruktor klasy Cherry.
	/// 
	/// @param window Referencja do obiektu sf::RenderWindow, na kt�rym wi�nie s� renderowane.
	/// @param position Pocz�tkowa pozycja wi�ni.
	/// @param type Typ wi�ni, determinuj�cy wygl�d.
	Cherry(sf::RenderWindow& window, sf::Vector2f position, std::string type);
	/// Metoda aktualizuj�ca stan wi�ni.
	///
	/// Metoda update() jest odpowiedzialna za aktualizacj� stanu wi�ni, np. jego pozycji czy wygl�du.
	void update();
	/// Metoda zwracaj�ca pozycj� wroga.
	///
	/// @return Obiekt sf::Vector2f reprezentuj�cy aktualn� pozycj� wi�ni.
	sf::Vector2f getPosition();
	sf::Sprite getSprite();



private:
	/// Referencja do obiektu sf::RenderWindow, na kt�rym wi�nie s� renderowani.
	sf::RenderWindow& window;
	/// Obiekt sf::Sprite reprezentuj�cy wi�nie.
	sf::Sprite sprite;
	/// Obiekt sf::Texture przechowuj�cy tekstur� wi�ni.
	sf::Texture texture;
};

