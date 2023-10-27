#include "Projectile.h"
#include <iostream>


Projectile::Projectile(sf::RenderWindow& window, sf::Vector2f position) : window(window) {
    if (!texture.loadFromFile("CharacterAssets/Idle (1).png")) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
    int newWidth = 30;
    int newHeight = 30;
    sprite.setScale(newWidth / sprite.getLocalBounds().width, newHeight / sprite.getLocalBounds().height);
    sprite.setPosition(position);
    sprite.setTexture(texture);
}

void Projectile::update() {
    window.draw(sprite);
    sprite.move(sf::Vector2f(20.0f, 0.0f));
}


bool Projectile::projectableReady() {

    if (sprite.getPosition().x > 800)
        return true;
    else
        return false;
}