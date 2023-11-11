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

	
	sf::Font font;
	if (!font.loadFromFile("MapAssets/Granesta.ttf")) {
		std::cout << "ttf error";
	}

	sf::Text text;
	text.setFont(font);
	text.setString("Level: " + std::to_string(mapCounter+1) + "/69");
	text.setCharacterSize(25);
	text.setPosition(10, 10);
	text.setFillColor(sf::Color::White);
	

	
	window.draw(sprite);	
	this->renderPlatforms();
	window.draw(text);
	
}

void BitmapHandler::renderPlatforms() {
	map = mapData.getMap(mapCounter);

	sf::Image tmpImage;
	sf::Texture tmpTexture;
	sf::Sprite tmpSprite;


	for (const auto& pair : map) {
		//std::cout << pair.first.x << ", " << pair.first.y <<  pair.second << std::endl;


		if (!tmpImage.loadFromFile("MapAssets/" + pair.second + ".png")) {
			return;
		}

		tmpTexture.loadFromImage(tmpImage);
		sf::Sprite tmpSprite(tmpTexture);
		tmpSprite.setPosition(pair.first);
		window.draw(tmpSprite);

	}



	auto it = enemiesRenderedOnMap.find(mapCounter);
	if (it == enemiesRenderedOnMap.end()) {
		enemiesRenderedOnMap.insert(mapCounter);

		enemies = mapData.getEnemy(mapCounter);

		for (const auto& pair : enemies) {
			 std::cout << pair.first.x << ", " << pair.first.y << pair.second << std::endl;
			std::cout << "qwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
			 createdEnemies.push_back(new Enemy(window, sf::Vector2f(pair.first.x, pair.first.y), pair.second));
		}
	
	}





}
void BitmapHandler::setMapIndex(int index) {
	this->mapCounter = index;
}


sf::FloatRect BitmapHandler::getSize() {
	return back.getGlobalBounds();
}

std::vector<Enemy*> BitmapHandler::getEnemies() {
	return createdEnemies;
}

void BitmapHandler::removeEnemy(int index) {



	if (index < createdEnemies.size()) {
		delete createdEnemies[index];
		createdEnemies.erase(createdEnemies.begin() + index);
	}
	

}