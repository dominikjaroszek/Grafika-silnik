#pragma once
#include <SFML/Graphics.hpp>
#include <Set>
#include "Enemy.h"
#include "MapData.h"
#include <set>

/// Klasa zarz¹dzaj¹ca mapami w grze.

class MapHandler
{
public:
	MapHandler(sf::RenderWindow& window);
	void setMapIndex(int index);
	std::vector<Enemy*> getEnemies();
	void removeEnemy(int index);
	void renderBitmap();
	std::vector<sf::Sprite> getPlatformSprites();
	

private:
	sf::RenderWindow& window;
	MapData mapData;
	std::vector<std::pair<sf::Vector2f, std::string>> map;
	int mapCounter;
	std::vector<std::pair<sf::Vector2f, std::string>> enemies;
	std::vector<Enemy*> createdEnemies;
	std::set<int> enemiesRenderedOnMap;
	std::vector<sf::Sprite> platformSprites;
	sf::Text text;
	sf::Font font;
	void loadTextures();
	std::set<std::string> imagesSet;
	std::map<std::string, sf::Texture> mapTextures;

	void renderPlatforms();
};

