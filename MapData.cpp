#include "MapData.h"


MapData::MapData() {
	maps[0] = { {sf::Vector2f(100,0), "platform_1"}, {sf::Vector2f(200,100), "platform_1"} };
	maps[1] = { {sf::Vector2f(300,300), "platform_1"}, {sf::Vector2f(500,400), "platform_1"} };
	maps[2] = { {sf::Vector2f(400,300), "platform_1"}, {sf::Vector2f(500,300), "platform_1"} };


    enemies[0] = { {sf::Vector2f(400,400), "enemy_1"}, {sf::Vector2f(200,200), "enemy_1"} };
    enemies[1] = { {sf::Vector2f(300,300), "enemy_1"}, {sf::Vector2f(600,600), "enemy_1"} };
}

std::vector<std::pair<sf::Vector2f, std::string>> MapData::getMap(int ID) {
    auto it = maps.find(ID);

    if (it != maps.end()) {
        return it->second;
    }
    else
        return {};
 
}

std::vector<std::pair<sf::Vector2f, std::string>> MapData::getEnemy(int ID) {
    auto it = enemies.find(ID);

    if (it != enemies.end()) {
        return it->second;
    }
    else
        return {};

}
