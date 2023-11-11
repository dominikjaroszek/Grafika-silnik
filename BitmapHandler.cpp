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

