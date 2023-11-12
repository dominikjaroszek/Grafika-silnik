#pragma once
#include <vector>
#include "Player.h"
#include "Projectile.h"
#include "BitmapHandler.h"

class CollissionsDetection
{
public:
	CollissionsDetection();
	void setPlatformSprites(std::vector<sf::Sprite> sprites);
	int playerCollisions(Player& player, sf::Vector2f move);
	int playerCollisions(Player& player);
	int testThread(Player& player);
	

private:
	std::vector<sf::Sprite> platformSprites;
};

