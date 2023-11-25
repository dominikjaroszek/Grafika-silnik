#include "BitmapHandler.h"
#include <iostream>

BitmapHandler::BitmapHandler(sf::RenderWindow& window): window(window) {

	if (!bitmapImage.loadFromFile("MapAssets/map.bmp")) {
		return;
	}
	texture.loadFromImage(bitmapImage);
	
	if (!bitmapImageFloor.loadFromFile("MapAssets/platform_floor.png")) {
		return;
	}
	textureFloor.loadFromImage(bitmapImageFloor);
	
	sprite.setTexture(texture);
	floor.setTexture(textureFloor);
	sprite.setScale(
		static_cast<float>(window.getSize().x) / sprite.getLocalBounds().width,
		static_cast<float>(window.getSize().y) / sprite.getLocalBounds().height
	);

	floor.setPosition(sf::Vector2f(0,550));

	this->renderBitmap();


	
}

void BitmapHandler::renderBitmap() {
	
	window.draw(sprite);	
	window.draw(floor);
}



sf::FloatRect BitmapHandler::getSize() {
	return floor.getGlobalBounds();
}

void BitmapHandler::drawFromFile(sf::RenderWindow& window, std::string path, float PositionX, float PositionY, float scaleX, float scaleY) {
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position(PositionX, PositionY);

	if (!texture.loadFromFile(path)) {
		return;
	}

	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setScale(sf::Vector2f(scaleX, scaleY));
	window.draw(sprite);
	
}


void BitmapHandler::saveToFile(std::string FileName, sf::Texture texture) {
	sf::Image image;
	image = texture.copyToImage();
	image.saveToFile(FileName);	
}

