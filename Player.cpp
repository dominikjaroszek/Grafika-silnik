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
    
   
}


void Player::update() {
    
    window.draw(sprite);
    //sprite.move(sf::Vector2f(5.f, 10.f));
}

void Player::move(sf::Vector2f move) {
    sprite.move(move);
}

