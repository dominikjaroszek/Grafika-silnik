#include "BitmapHandler.h"

BitmapHandler::BitmapHandler(sf::RenderWindow& window): window(window) {

	if (!bitmapImage.loadFromFile("CharacterAssets/map.bmp")) {
		return;
	}
	texture.loadFromImage(bitmapImage);
	

	this->renderBitmap();
}

void BitmapHandler::renderBitmap() {
	sf::Sprite sprite(texture);
	if (!window.isOpen())
		return;

	sprite.setScale(
		static_cast<float>(window.getSize().x) / sprite.getLocalBounds().width,
		static_cast<float>(window.getSize().y) / sprite.getLocalBounds().height
	);
	window.draw(sprite);	
}