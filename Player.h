#pragma once
#include "UpdatableObject.h"
#include "Projectile.h"


class Player : public UpdatableObject{
public:
	Player(sf::RenderWindow& window, sf::Vector2f position);
	//void init(sf::RenderWindow& window, sf::Vector2f position);
	void update() override;
	void move(sf::Vector2f move);
	sf::Vector2f playerPosition();
	void jump();
	void moveAnimation();
	
	
	
private:
	sf::Sprite sprite;
	sf::RenderWindow& window;
	sf::Texture texture;
	int gravity_speed;
	float bottomY;
	float animationIndex;
	void updateAnimationIdle(int animationIndex);
};

