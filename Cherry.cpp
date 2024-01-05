#include "Cherry.h"

Cherry::Cherry(sf::RenderWindow& window, sf::Vector2f position, std::string type) :window(window) {

    if (!texture.loadFromFile("MapAssets/cherry.png")) {
        std::cout << "Err";
    }

    sprite.setTexture(texture);
    sprite.setPosition(position);
    int newWidth = 100;
    int newHeight = 100;
    sprite.setScale(newWidth / sprite.getLocalBounds().width, newHeight / sprite.getLocalBounds().height);

    window.draw(sprite);
};

void Cherry::update() {

    sprite.setTexture(texture);

    window.draw(sprite);

}

sf::Vector2f Cherry::getPosition() {
    return sprite.getPosition();

}

sf::Sprite Cherry::getSprite() {
    return sprite;
}

