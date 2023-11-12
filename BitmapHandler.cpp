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
	mapCounter = 0;
	

	
}

void BitmapHandler::renderBitmap() {
	sf::Sprite sprite(texture);
	
	sprite.setScale(
		static_cast<float>(window.getSize().x) / sprite.getLocalBounds().width,
		static_cast<float>(window.getSize().y) / sprite.getLocalBounds().height
	);

	
	window.draw(sprite);	
	this->renderPlatforms();
	
}

void BitmapHandler::renderPlatforms() {
	map = mapData.getMap(mapCounter);

	sf::Image tmpImage;
	sf::Texture tmpTexture;
	sf::Sprite tmpSprite;


	for (const auto& pair : map) {
		std::cout << pair.first.x << ", " << pair.first.y <<  pair.second << std::endl;

		
		if (!tmpImage.loadFromFile("MapAssets/" + pair.second + ".png")) {
			return;
		}
	
		tmpTexture.loadFromImage(tmpImage);
		sf::Sprite tmpSprite(tmpTexture);
		tmpSprite.setPosition(pair.first);
		window.draw(tmpSprite);

	}
}
void BitmapHandler::setMapIndex(int index) {
	this->mapCounter = index;
}


sf::FloatRect BitmapHandler::getSize() {
	return back.getGlobalBounds();
}
