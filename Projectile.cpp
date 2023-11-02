#include "Projectile.h"
#include <iostream>
#include <random>


Projectile::Projectile(sf::RenderWindow& window, sf::Vector2f position, int direction, bool moving) : window(window) {
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distribution(1, 5);

    int r = distribution(gen);

    if (!texture.loadFromFile("CharacterAssets/rock_"+ std::to_string((int)r) +".png")) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
    int newWidth = 25;
    int newHeight = 25;
    position = sf::Vector2f(position.x, position.y+20);
    if (direction < 0)
        newWidth *= -1;
    sprite.setScale(newWidth / sprite.getLocalBounds().width, newHeight / sprite.getLocalBounds().height);
    sprite.setPosition(position);
    sprite.setTexture(texture);
    this->direction = direction;
    speedHorizontal = 13;
    speedVertical = 0;
    decreaseVerticalSpeed = 1;

    if (moving)
        speedHorizontal += 10;
  
   
}

void Projectile::update() {
    window.draw(sprite);

    if (sprite.getPosition().y >= 525)
        return;

    if(direction>0)
        sprite.move(sf::Vector2f(speedHorizontal * 1.0f, speedVertical * 1.0f));
    else
        sprite.move(sf::Vector2f(speedHorizontal * -1.0f, speedVertical* 1.0f));
    

    if (speedHorizontal > 4) {
        speedHorizontal -= 0.3;
        speedVertical += 0.1;
    }
    else {
        speedVertical += 0.3;
    }
    
}


bool Projectile::projectableReady() {

    sf::Vector2f position = sprite.getPosition();

    if (position.x > 800 || position.x<0 || position.y >= 525)
        return true;
    else
        return false;
}