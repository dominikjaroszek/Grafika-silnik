#pragma once
#include "MapData.h"
#include <SFML/Graphics.hpp>




class BitmapHandler
{
public:
	BitmapHandler(sf::RenderWindow& window) ;
	void renderBitmap();
	sf::FloatRect getSize();
	void setMapIndex(int index);

private:
	MapData mapData;
	std::vector<std::pair<sf::Vector2f, std::string>> map;
	int mapCounter;
	sf::RenderWindow& window;
	sf::Image bitmapImage;
	sf::Texture texture;


	sf::Image bitmapImageBack;
	sf::Texture textureBack;
	sf::Sprite back;

	void renderPlatforms();
	
};

