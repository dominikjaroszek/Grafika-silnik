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
    IdleAnimationIndex = 1;
    WalkAnimationIndex = 1;
    JumpAnimationIndex = 1;
    bottomY = 0;
    isMovingX = false;
    isMovingY = false;
    lastPos = sf::Vector2f(0, 0);
 
}

void Player::update() {
    
    bottomY = sprite.getPosition().y + sprite.getLocalBounds().height;

    gravity_speed += 1;

    sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + gravity_speed));
    
    if (sprite.getPosition().y > 400) {
        sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 400)); 
        gravity_speed = 0; 
    }

    IdleAnimationIndex += 0.2;
    if (IdleAnimationIndex >= 15)
        IdleAnimationIndex = 1;
    
    if (lastPos.x != sprite.getPosition().x)
        isMovingX = true;
    else
        isMovingX = false;


    if (lastPos.y != sprite.getPosition().y)
        isMovingY = true;
    else
        isMovingY = false;

    lastPos = sprite.getPosition();


    if(!isMovingX)
        this->updateAnimationIdle();

    if (isMovingY)
        this->updateAnimationJump();


    window.draw(sprite);
}

sf::Vector2f Player::playerPosition() {
    return sprite.getPosition();

}

int Player::getDirection() {
    if (sprite.getScale().x < 0)
        return -1;
    else
        return 1;
}

void Player::move(sf::Vector2f move) {
    sprite.move(move);
    if (move.x > 0) {
        if (sprite.getScale().x < 0)
            sprite.move(sf::Vector2f(-50, 0));
        sprite.setScale(100 / sprite.getLocalBounds().width, 100 / sprite.getLocalBounds().height);

    }
    else {
        if (sprite.getScale().x > 0)
            sprite.move(sf::Vector2f(50, 0));
        sprite.setScale(-100 / sprite.getLocalBounds().width, 100 / sprite.getLocalBounds().height);
    }

    this->updateAnimationWalk();
}


void Player::jump() {
    if(sprite.getPosition().y >= 400)
        this->gravity_speed = -20;
}


void Player::updateAnimationIdle() {

    std::string fileName = "CharacterAssets/Idle (" + std::to_string((int)IdleAnimationIndex) + ").png";
    if (!texture.loadFromFile(fileName)) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
}

void Player::updateAnimationWalk() {

    isMovingX = true;

    WalkAnimationIndex += 0.5;
    if (WalkAnimationIndex >= 15)
        WalkAnimationIndex = 1;

    std::string fileName = "CharacterAssets/Walk (" + std::to_string((int)WalkAnimationIndex) + ").png";
    if (!texture.loadFromFile(fileName)) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);

}

void Player::updateAnimationJump() {

    isMovingY = true;

    JumpAnimationIndex += 0.2;
    if (JumpAnimationIndex >= 15)
        JumpAnimationIndex = 1;

    std::string fileName = "CharacterAssets/Jump (" + std::to_string((int)JumpAnimationIndex) + ").png";
    if (!texture.loadFromFile(fileName)) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);

}