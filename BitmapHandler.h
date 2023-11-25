#pragma once
#include "MapData.h"

class BitmapHandler
{
public:
	BitmapHandler(sf::RenderWindow& window);
	void renderBitmap();
	sf::FloatRect getSize();
	static void drawFromFile(sf::RenderWindow& window, std::string path, float PositionX, float PositionY, float scaleX, float scaleY);
	static void saveToFile(std::string FileName, sf::Texture texture);
	

private:
	sf::RenderWindow& window;
	sf::Image bitmapImage;
	sf::Texture texture;
	sf::Sprite sprite;


	sf::Image bitmapImageFloor;
	sf::Texture textureFloor;
	sf::Sprite floor;

};

