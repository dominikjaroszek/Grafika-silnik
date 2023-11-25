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
	/// Ustawia wektor platform, z kt�rymi ma by� sprawdzana kolizja.
	///
	/// @param sprites Wektor obiekt�w sf::Sprite reprezentuj�cych platformy.
	void setPlatformSprites(std::vector<sf::Sprite> sprites);
	/// Sprawdza kolizje gracza z platformami podczas ruchu.
	/// 
	/// Sprawdza, czy kolizja wyst�pi mi�dzy graczem a platformami po zastosowaniu ruchu.
	/// @param player Referencja do obiektu Player, kt�ry jest sprawdzany pod k�tem kolizji.
	/// @param move Wektor ruchu gracza.
	/// @return Warto�� logiczna, czy dosz�o do kolizji (1 - tak, 0 - nie).
	int playerCollisions(Player& player, sf::Vector2f move);
	/// Sprawdza kolizje gracza z platformami podczas ruchu.
	/// 
	/// Sprawdza, czy kolizja wyst�pi mi�dzy graczem a platformami bez zastosowaniu ruchu.
	/// @param player Referencja do obiektu Player, kt�ry jest sprawdzany pod k�tem kolizji.
	/// @return Warto�� logiczna, czy dosz�o do kolizji (1 - tak, 0 - nie).
	int playerCollisions(Player& player);
	
	

private:
	/// Wektor obiekt�w sf::Sprite reprezentuj�cych platformy.
	std::vector<sf::Sprite> platformSprites;
};

