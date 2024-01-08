#include "MapHandler.h"

MapHandler::MapHandler(sf::RenderWindow& window) : window(window) {

	
	if (!font.loadFromFile("MapAssets/Granesta.ttf")) {
		std::cout << "ttf error";
	}
	this->loadTextures();
	

	this->renderBitmap();
	mapCounter = 0;
	score = 0;


}

void MapHandler::loadTextures() {
	imagesSet = mapData.getAllMaps();

	for (auto& map : imagesSet) {
		sf::Image tmpImage;
		if (!tmpImage.loadFromFile("MapAssets/" + map + ".png")) {
			return;
		}
		sf::Texture tmpTexture;
		tmpTexture.loadFromImage(tmpImage);
		mapTextures[map] = tmpTexture;
	}
		
}

void MapHandler::renderBitmap() {

	text.setFont(font);
	text.setString("Level: " + std::to_string(mapCounter + 1) + "/5");
	text.setCharacterSize(25);
	text.setPosition(10, 10);
	text.setFillColor(sf::Color::White);

	textScore.setFont(font);
	textScore.setString("Score: " + std::to_string(score));
	textScore.setCharacterSize(20);
	textScore.setPosition(10, 40);
	textScore.setFillColor(sf::Color::White);

	this->renderPlatforms();
	window.draw(text);
	window.draw(textScore);

}

void MapHandler::renderPlatforms() {
	
	map = mapData.getMap(mapCounter);

	
	sf::Sprite tmpSprite;

	platformSprites.clear();
	for (const auto& pair : map) {
		sf::Sprite tmpSprite(mapTextures[pair.second]);
		tmpSprite.setPosition(pair.first);
		platformSprites.push_back(tmpSprite);
		window.draw(tmpSprite);

	}
	
	
	auto it = enemiesRenderedOnMap.find(mapCounter);
	if (it == enemiesRenderedOnMap.end()) {
		enemiesRenderedOnMap.insert(mapCounter);

		enemies = mapData.getEnemy(mapCounter);

		for (const auto& pair : enemies) {
			createdEnemies.push_back(new Enemy(window, sf::Vector2f(pair.first.x, pair.first.y), pair.second));
		}

	}

	it = cherriesRenderedOnMap.find(mapCounter);
	if (it == cherriesRenderedOnMap.end()) {
		cherriesRenderedOnMap.insert(mapCounter);

		cherries = mapData.getCherry(mapCounter);

		for (const auto& pair : cherries) {
			createdCherries.push_back(new Cherry(window, sf::Vector2f(pair.first.x, pair.first.y), pair.second));
		}

	}

	

}
void MapHandler::setMapIndex(int index) {
	this->mapCounter = index;
}

std::vector<Enemy*> MapHandler::getEnemies() {
	return createdEnemies;
}

std::vector<Cherry*> MapHandler::getCherry() {
	return createdCherries;
}

void MapHandler::removeEnemy(int index) {

	if (index < createdEnemies.size()) {
		delete createdEnemies[index];
		createdEnemies.erase(createdEnemies.begin() + index);
	}

}

void MapHandler::removeCherry(int index) {

	if (index < createdCherries.size()) {
		delete createdCherries[index];
		createdCherries.erase(createdCherries.begin() + index);
	}

}

std::vector<sf::Sprite> MapHandler::getPlatformSprites() {
	return platformSprites;
}

void MapHandler::addScore() {
	score += 1;
}
void MapHandler::resetScore() {
	score = 0;
}

int MapHandler::getMapIndex() {
	return mapCounter;
}

int MapHandler::getCherryNum() {
	return mapData.getCherry(mapCounter).size();
}

void MapHandler::renderEndingScreen() {
	sf::Text endingText;
	endingText.setFont(font);
	endingText.setString("END");
	endingText.setCharacterSize(70);
	endingText.setPosition(350, 250);
	endingText.setFillColor(sf::Color::White);
	window.draw(endingText);

	endingText.setString("Score: " + std::to_string(score));
	endingText.setPosition(350, 350);
	endingText.setCharacterSize(25);
	window.draw(endingText);
}