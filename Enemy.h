#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Enemy
{
public:
	Enemy(sf::RenderWindow& window, sf::Vector2f position, std::string type);
	void update();
	sf::Vector2f getPosition();


private:
	sf::RenderWindow& window;
	sf::Sprite sprite;
	sf::Texture texture;
};

