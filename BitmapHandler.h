#pragma once
#include <SFML/Graphics.hpp>
class BitmapHandler
{
public:
	BitmapHandler(sf::RenderWindow& window);
	void renderBitmap();

private:
	sf::RenderWindow& window;
	sf::Image bitmapImage;
	sf::Texture texture;
	
};

