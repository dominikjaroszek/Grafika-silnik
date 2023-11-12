#pragma once
#include <SFML/Graphics.hpp>
class BitmapHandler
{
public:
	BitmapHandler(sf::RenderWindow& window);
	void renderBitmap();
	sf::FloatRect getSize();

private:
	sf::RenderWindow& window;
	sf::Image bitmapImage;
	sf::Image bitmapImageBack;
	sf::Texture texture;
	sf::Texture textureBack;
	sf::Sprite back;
	
};

