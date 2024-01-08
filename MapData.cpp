#include "MapData.h"


MapData::MapData() {
	maps[0] = { {sf::Vector2f(300,400), "platform_1"} };
	maps[1] = { {sf::Vector2f(300,300), "platform_1"}, {sf::Vector2f(500,400), "platform_1"} };
	maps[2] = { {sf::Vector2f(300,400), "platform_1"}, {sf::Vector2f(500,300), "platform_1"} };
	maps[3] = { {sf::Vector2f(400,300), "platform_1"}, {sf::Vector2f(500,300), "platform_1"} };
	maps[4] = { {sf::Vector2f(100,300), "platform_1"}, {sf::Vector2f(250,150), "platform_1"} };

    enemies[0] = { {sf::Vector2f(300,300), "enemy_1"}};
    enemies[1] = { {sf::Vector2f(300,200), "enemy_1"}};
    enemies[2] = { {sf::Vector2f(450,200), "enemy_1"}};
    enemies[3] = { {sf::Vector2f(400,200), "enemy_1"}};
    enemies[4] = { {sf::Vector2f(400,200), "enemy_1"}};

    cherries[0] = { {sf::Vector2f(200,400), "cherry"}, {sf::Vector2f(500,300), "cherry"} };
    cherries[1] = { {sf::Vector2f(300,250), "cherry"}};
    cherries[2] = { {sf::Vector2f(200,200), "cherry"}};
    cherries[3] = { {sf::Vector2f(400,260), "cherry"}};
    cherries[4] = { {sf::Vector2f(100,400), "cherry"}, {sf::Vector2f(500,250), "cherry"}, {sf::Vector2f(150,250), "cherry"} };
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


std::vector<std::pair<sf::Vector2f, std::string>> MapData::getCherry(int ID) {
    auto it = cherries.find(ID);

    if (it != cherries.end()) {
        return it->second;
    }
    else
        return {};

}




std::set<std::string> MapData::getAllMaps() {

    std::set<std::string> mapsVector;

    for (const auto& mapEntry : maps) {
        const auto& vectorOfPairs = mapEntry.second;

        for (const auto& pair : vectorOfPairs) {
            mapsVector.insert(pair.second);
        }
    }

    return mapsVector;
}
