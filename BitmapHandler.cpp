#include "BitmapHandler.h"

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
	//sf::Sprite back(textureBack);
	back.setTexture(textureBack);
	if (!window.isOpen())
		return;

	sprite.setScale(
		static_cast<float>(window.getSize().x) / sprite.getLocalBounds().width,
		static_cast<float>(window.getSize().y) / sprite.getLocalBounds().height
	);

	back.setScale(0.3,0.3
		/*static_cast<float>(window.getSize().x) / 100,
		static_cast<float>(window.getSize().y) / back.getLocalBounds().height*/
	);

	//back.move(sf::Vector2f(3.0f, 2.0f));
	back.setPosition(sf::Vector2f(200.0f, 450.0f));

	//back.setOrigin(sf::Vector2f(back.getLocalBounds().width, back.getLocalBounds().height));
	
	window.draw(sprite);	
	window.draw(back);
}

sf::FloatRect BitmapHandler::getSize() {
	return back.getGlobalBounds();
}