#pragma once
#include "MapData.h"

class BitmapHandler
{
public:
	BitmapHandler(sf::RenderWindow& window);
	void renderBitmap();
	sf::FloatRect getSize();
	

private:
	sf::RenderWindow& window;
	sf::Image bitmapImage;
	sf::Texture texture;
	sf::Sprite sprite;


	sf::Image bitmapImageFloor;
	sf::Texture textureFloor;
	sf::Sprite floor;

};

