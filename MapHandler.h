#pragma once
#include <SFML/Graphics.hpp>
#include <Set>
#include "Enemy.h"
#include "MapData.h"

class MapHandler
{
public:
	MapHandler(sf::RenderWindow& window);
	void setMapIndex(int index);
	std::vector<Enemy*> getEnemies();
	void removeEnemy(int index);
	void renderBitmap();

private:
	sf::RenderWindow& window;
	MapData mapData;
	std::vector<std::pair<sf::Vector2f, std::string>> map;
	int mapCounter;
	std::vector<std::pair<sf::Vector2f, std::string>> enemies;
	std::vector<Enemy*> createdEnemies;
	std::set<int> enemiesRenderedOnMap;

	void renderPlatforms();
};

