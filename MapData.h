#pragma once
#include <SFML/Graphics.hpp>
#include <Vector>
#include <Map>

class MapData
{
public:
	MapData();
	std::vector<std::pair<sf::Vector2f, std::string>> getMap(int ID);
	std::vector<std::pair<sf::Vector2f, std::string>> getEnemy(int ID);

private:
	std::map<int, std::vector<std::pair<sf::Vector2f, std::string>>> maps;
	std::map<int, std::vector<std::pair<sf::Vector2f, std::string>>> enemies;

};

