#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/// Klasa reprezentuj¹ca wiœnie w grze.
///
/// Klasa Cherry odpowiada za reprezentacjê i aktualizacjê stanu wiœni w grze.
class Cherry
{
public:
	/// Konstruktor klasy Cherry.
	/// 
	/// @param window Referencja do obiektu sf::RenderWindow, na którym wiœnie s¹ renderowane.
	/// @param position Pocz¹tkowa pozycja wiœni.
	/// @param type Typ wiœni, determinuj¹cy wygl¹d.
	Cherry(sf::RenderWindow& window, sf::Vector2f position, std::string type);
	/// Metoda aktualizuj¹ca stan wiœni.
	///
	/// Metoda update() jest odpowiedzialna za aktualizacjê stanu wiœni, np. jego pozycji czy wygl¹du.
	void update();
	/// Metoda zwracaj¹ca pozycjê wroga.
	///
	/// @return Obiekt sf::Vector2f reprezentuj¹cy aktualn¹ pozycjê wiœni.
	sf::Vector2f getPosition();
	sf::Sprite getSprite();



private:
	/// Referencja do obiektu sf::RenderWindow, na którym wiœnie s¹ renderowani.
	sf::RenderWindow& window;
	/// Obiekt sf::Sprite reprezentuj¹cy wiœnie.
	sf::Sprite sprite;
	/// Obiekt sf::Texture przechowuj¹cy teksturê wiœni.
	sf::Texture texture;
};

