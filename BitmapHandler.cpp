#include "BitmapHandler.h"
#include <iostream>

BitmapHandler::BitmapHandler(sf::RenderWindow& window): window(window) {

	if (!bitmapImage.loadFromFile("MapAssets/map.bmp")) {
		return;
	}
	texture.loadFromImage(bitmapImage);
	
	if (!bitmapImageBack.loadFromFile("MapAssets/nwm.png")) {
		return;
	}
	textureBack.loadFromImage(bitmapImageBack);
	

	this->renderBitmap();


	
}

void BitmapHandler::renderBitmap() {
	sf::Sprite sprite(texture);
	
	sprite.setScale(
		static_cast<float>(window.getSize().x) / sprite.getLocalBounds().width,
		static_cast<float>(window.getSize().y) / sprite.getLocalBounds().height
	);

	window.draw(sprite);	
	
}



sf::FloatRect BitmapHandler::getSize() {
	return back.getGlobalBounds();
}

