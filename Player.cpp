#include "Player.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(sf::RenderWindow& window, sf::Vector2f position) : window(window) {
    if (!texture.loadFromFile("CharacterAssets/Idle (1).png")) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
    int newWidth = 100;
    int newHeight = 100;
    sprite.setScale(newWidth / sprite.getLocalBounds().width, newHeight / sprite.getLocalBounds().height);
    sf::Vector2f loc(200.0f, 400.0f);
    sprite.setPosition(loc);
    sprite.setTexture(texture);
    gravity_speed = 1;
    animationIndex = 1;
 
}




void Player::update() {
    
    bottomY = sprite.getPosition().y + sprite.getLocalBounds().height;

    gravity_speed += 1;

    sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + gravity_speed));
    
    if (sprite.getPosition().y > 400) {
        sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 400)); 
        gravity_speed = 0; 
    }

    animationIndex += 0.2;
    if (animationIndex >= 15)
        animationIndex = 1;
    this->updateAnimationIdle((int)(animationIndex));

    window.draw(sprite);

}

void Player::move(sf::Vector2f move) {
    sprite.move(move);
}


void Player::jump() {
    if(sprite.getPosition().y >= 400)
        this->gravity_speed = -20;
}

sf::Vector2f Player::playerPosition() {
    return sprite.getPosition();
   
}

void Player::updateAnimationIdle(int animationIndex) {

    std::string fileName = "CharacterAssets/Idle ("+std::to_string(animationIndex)+").png";
    if (!texture.loadFromFile(fileName)) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
}

void Player::moveAnimation() {

}