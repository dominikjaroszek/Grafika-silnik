#include "Player.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(sf::RenderWindow& window, sf::Vector2f position) : window(window) {
    if (!texture.loadFromFile("CharacterAssets/Idle (1).png", sf::IntRect(0, 0, 300, 500))) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
    sprite.setScale(0.2f, 0.2f);
    //std::cout << sprite.getGlobalBounds().height;
    sprite.setPosition(sf::Vector2f(position.x, 400));
    sprite.setTexture(texture);
    gravity_speed = 1;
    IdleAnimationIndex = 1;
    WalkAnimationIndex = 1;
    JumpAnimationIndex = 1;
    bottomY = 0;
    isMovingX = false;
    isMovingY = false;
    lastPos = sf::Vector2f(0, 0);
    mapIndex = 0;
    canJump = true;
 
}

void Player::update() {
    
 
    gravity_speed += 1;
   
    if (sprite.getPosition().y < 0) {
        sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 0));
        gravity_speed = 0;
    }
        
   
    if (sprite.getPosition().y > 450) {
       sprite.setPosition(sf::Vector2f(sprite.getPosition().x, 450)); 
       gravity_speed = 0; 
       canJump = true;
    }

    sprite.getGlobalBounds().getPosition().y;
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



    sf::Vector2f pos = sprite.getPosition();
    if (pos.x > 800) {
        sprite.setPosition(sf::Vector2f(0, pos.y));
        mapIndex += 1;
    }
    else if (pos.x < 0) {
        if (mapIndex > 0) {
            sprite.setPosition(sf::Vector2f(800, pos.y));
            mapIndex -= 1;
        }
       
    }
   
    window.draw(sprite);

}

void Player::updatePlayerY() {
    sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + gravity_speed));
}


int Player::getMapIndex() {
    return mapIndex;
}

sf::Vector2f Player::playerPosition() {
    return sprite.getPosition();

}

sf::FloatRect Player::playerSize() {
    return sprite.getGlobalBounds();

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
        sprite.setScale(0.2f,0.2f);

    }
    else if(move.x <0){
        if (sprite.getScale().x > 0)
            sprite.move(sf::Vector2f(50, 0));
        sprite.setScale(-0.2f, 0.2f);
    }

    this->updateAnimationWalk();
}


void Player::jump() {
    
    if (canJump) {
        canJump = false;
        this->gravity_speed = -20;
    }
   
}


void Player::updateAnimationIdle() {

    std::string fileName = "CharacterAssets/Idle (" + std::to_string((int)IdleAnimationIndex) + ").png";
    if (!texture.loadFromFile(fileName, sf::IntRect(0, 0, 300, 500))) {
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

    JumpAnimationIndex += 0.1;
    if (JumpAnimationIndex >= 15)
        JumpAnimationIndex = 1;

    std::string fileName = "CharacterAssets/Jump (" + std::to_string((int)JumpAnimationIndex) + ").png";
    if (!texture.loadFromFile(fileName, sf::IntRect(0, 0, 300, 500))) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
 

}

bool Player::isMovingHorizontal() {
    return isMovingX;
}

void Player::playerSetPosition() {
    sprite.setPosition(lastPosition);
}

void Player::playerSetPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

float Player::getGravitySpeed() {
    return gravity_speed;
}

void Player::setGravityZero() {
    gravity_speed = 0;
}

void Player::setCanJump() {
    canJump = true;
}