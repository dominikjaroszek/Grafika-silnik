#pragma once
#include "UpdatableObject.h"
class Projectile : public UpdatableObject
{
public:
	Projectile();
	Projectile(sf::RenderWindow& window, sf::Vector2f position);
	void update();
	bool projectableReady();
	

private:
	sf::Sprite sprite;
	sf::RenderWindow& window;
	sf::Texture texture;

};

