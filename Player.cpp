#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(sf::RenderWindow& window, sf::Vector2f position) : window(window) {
    if (!texture.loadFromFile("Idle.png")) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
    int newWidth = 100;
    int newHeight = 100;
    sprite.setScale(newWidth / sprite.getLocalBounds().width, newHeight / sprite.getLocalBounds().height);
    sf::Vector2f loc(200.0f, 100.0f);
    sprite.setPosition(loc);
    sprite.setTexture(texture);
    gravity_speed = 1;
    
   
}


void Player::update() {
    
    
    gravity_speed += 1;

    sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + gravity_speed));

    // Check if the player is on the ground
    if (sprite.getPosition().y > 400) {
        sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 400)); // Ensure the character doesn't fall through the ground
        gravity_speed = 0; // Reset gravity speed when on the ground
    }

    window.draw(sprite);

}

void Player::move(sf::Vector2f move) {
    sprite.move(move);
}


void Player::jump() {
    if(sprite.getPosition().y >= 400)
        this->gravity_speed = -20;
    
}