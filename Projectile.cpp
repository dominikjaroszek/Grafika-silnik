#include "Projectile.h"
#include <iostream>


Projectile::Projectile(sf::RenderWindow& window, sf::Vector2f position, int direction) : window(window) {
    if (!texture.loadFromFile("CharacterAssets/Idle (1).png")) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
    int newWidth = 30;
    int newHeight = 30;
    sprite.setScale(newWidth / sprite.getLocalBounds().width, newHeight / sprite.getLocalBounds().height);
    sprite.setPosition(position);
    sprite.setTexture(texture);
    this->direction = direction;
}

void Projectile::update() {
    window.draw(sprite);
    if(direction>0)
        sprite.move(sf::Vector2f(20.0f, 0.0f));
    else
        sprite.move(sf::Vector2f(-20.0f, 0.0f));
}


bool Projectile::projectableReady() {

    sf::Vector2f position = sprite.getPosition();

    if (position.x > 800 || position.x<0)
        return true;
    else
        return false;
}