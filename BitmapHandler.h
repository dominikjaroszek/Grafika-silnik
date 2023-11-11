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


	sf::Image bitmapImageBack;
	sf::Texture textureBack;
	sf::Sprite back;

};

