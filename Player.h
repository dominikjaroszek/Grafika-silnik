#pragma once
#include "UpdatableObject.h"


class Player : public UpdatableObject{
public:
	Player(sf::RenderWindow& window, sf::Vector2f position);
	void update() override;
	void move(sf::Vector2f move);

	void jump();
	
	
private:
	sf::Sprite sprite;
	sf::RenderWindow& window;
	sf::Texture texture;
	int gravity_speed;
};

