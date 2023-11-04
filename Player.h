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
	sf::FloatRect playerSize();
	void jump();
	int getDirection();
	bool isMovingHorizontal();
	void playerSetPosition();
	sf::Vector2f lastPosition;
	bool collisionY;
	bool isJumping;

	
	
	
private:
	sf::Sprite sprite;
	sf::RenderWindow& window;
	sf::Texture texture;
	int gravity_speed;
	float bottomY;
	float IdleAnimationIndex;
	float WalkAnimationIndex;
	float JumpAnimationIndex;
	bool isMovingX;
	bool isMovingY;
	sf::Vector2f lastPos;
	void updateAnimationIdle();
	void updateAnimationJump();
	void updateAnimationWalk();
	
};

