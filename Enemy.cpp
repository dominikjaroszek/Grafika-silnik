#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow& window, sf::Vector2f position, std::string type):window(window){

    if (!texture.loadFromFile("EnemyAssets/"+type+".png")) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
    sprite.setPosition(position);
    int newWidth = 150;
    int newHeight = 150;
    sprite.setScale(newWidth / sprite.getLocalBounds().width, newHeight / sprite.getLocalBounds().height);

    window.draw(sprite);
};

void Enemy::update() {
 
    sprite.setTexture(texture);
  
    window.draw(sprite);
   
}

sf::Vector2f Enemy::getPosition() {
    return sprite.getPosition();

}

