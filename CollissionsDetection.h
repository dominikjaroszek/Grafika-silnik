#pragma once
#include "Player.h"
#include "Projectile.h"
#include "BitmapHandler.h"

class CollissionsDetection
{
public:
	CollissionsDetection(BitmapHandler& bitmap);

	int playerCollisions(Player& player);
	bool projectileCollision(Projectile& projectile);

private:
	BitmapHandler bitmap;
};

