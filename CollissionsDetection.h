#pragma once
#include <vector>
#include "Player.h"
#include "Projectile.h"
#include "BitmapHandler.h"

/// Klasa do wykrycia kolizji gracza z platformami.
///
/// Klasa CollissionsDetection odpowiada za wykrywanie kolizji gracza z platformami na ekranie.
class CollissionsDetection
{
public:
	/// Konstruktor klasy CollissionsDetection.
	/// 
	/// Inicjuje obiekt CollissionsDetection.
	CollissionsDetection();
	/// Ustawia wektor platform, z którymi ma byæ sprawdzana kolizja.
	///
	/// @param sprites Wektor obiektów sf::Sprite reprezentuj¹cych platformy.
	void setPlatformSprites(std::vector<sf::Sprite> sprites);
	/// Sprawdza kolizje gracza z platformami podczas ruchu.
	/// 
	/// Sprawdza, czy kolizja wyst¹pi miêdzy graczem a platformami po zastosowaniu ruchu.
	/// @param player Referencja do obiektu Player, który jest sprawdzany pod k¹tem kolizji.
	/// @param move Wektor ruchu gracza.
	/// @return Wartoœæ logiczna, czy dosz³o do kolizji (1 - tak, 0 - nie).
	int playerCollisions(Player& player, sf::Vector2f move);
	/// Sprawdza kolizje gracza z platformami podczas ruchu.
	/// 
	/// Sprawdza, czy kolizja wyst¹pi miêdzy graczem a platformami bez zastosowaniu ruchu.
	/// @param player Referencja do obiektu Player, który jest sprawdzany pod k¹tem kolizji.
	/// @return Wartoœæ logiczna, czy dosz³o do kolizji (1 - tak, 0 - nie).
	int playerCollisions(Player& player);
	
	

private:
	/// Wektor obiektów sf::Sprite reprezentuj¹cych platformy.
	std::vector<sf::Sprite> platformSprites;
};

