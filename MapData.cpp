#include "MapData.h"


MapData::MapData() {
	maps[0] = { {sf::Vector2f(0,0), "platform_1"}, {sf::Vector2f(100,100), "platform_1"} };
	maps[1] = { {sf::Vector2f(300,300), "platform_1"}, {sf::Vector2f(500,400), "platform_1"} };
	maps[2] = { {sf::Vector2f(400,300), "platform_1"}, {sf::Vector2f(500,300), "platform_1"} };
}

std::vector<std::pair<sf::Vector2f, std::string>> MapData::getMap(int ID) {
    auto it = maps.find(ID);

    if (it != maps.end()) {
        return it->second;
    }
    else
        return {};
 
}
