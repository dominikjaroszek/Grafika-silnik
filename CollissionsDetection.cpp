#include "CollissionsDetection.h"
#include <iostream>

CollissionsDetection::CollissionsDetection(){}


void CollissionsDetection::setPlatformSprites(std::vector<sf::Sprite> sprites) {
	platformSprites = sprites;
}


int CollissionsDetection::playerCollisions(Player& player, sf::Vector2f move) {
	
	float playerX = player.playerPosition().x;
	float playerY = player.playerPosition().y;
	float playerW = player.playerSize().width;
	float playerH = player.playerSize().height;

	for (sf::Sprite sprite : platformSprites) {
		float spriteX = sprite.getPosition().x;
		float spriteY = sprite.getPosition().y;
		float spriteW = sprite.getGlobalBounds().width;
		float spriteH = sprite.getGlobalBounds().height;

		//std::cout << "0\n";
		
		

		sf::Vector2f currentPositon = player.playerPosition();
		player.move(move);

		if (player.playerSize().intersects(sprite.getGlobalBounds())) {
			std::cout<< "collision";
			//player.playerSetPosition(currentPositon);
			player.move(-move);
			return 1;
		}
	}


	return 0;
}

int CollissionsDetection::playerCollisions(Player& player) {

	float playerX = player.playerPosition().x;
	float playerY = player.playerPosition().y;
	float playerW = player.playerSize().width;
	float playerH = player.playerSize().height;

	for (sf::Sprite sprite : platformSprites) {
		float spriteX = sprite.getPosition().x;
		float spriteY = sprite.getPosition().y;
		float spriteW = sprite.getGlobalBounds().width;
		float spriteH = sprite.getGlobalBounds().height;

	//	std::cout << "0\n";

		sf::Vector2f currentPositon = player.playerPosition();
		float gravity = player.getGravitySpeed();

		bool underPlatform = false;
		if (player.playerPosition().y > spriteY)
			underPlatform = true;

		player.move(sf::Vector2f(0, gravity));

		if (player.playerSize().intersects(sprite.getGlobalBounds()) && (player.playerPosition().y  < spriteY + spriteH && underPlatform)) {
			std::cout << "collisionBOTTOM";
			//player.playerSetPosition(currentPositon);
		//	player.playerSetPosition(sf::Vector2f(playerX, spriteY - playerH));

			player.playerSetPosition(sf::Vector2f(playerX, spriteY + spriteH + 1));
			//player.move(sf::Vector2f(0, spriteY - playerH - gravity));
			player.setGravityZero();
		}

		if (player.playerSize().intersects(sprite.getGlobalBounds()) && (player.playerPosition().y + playerH > spriteY && player.playerPosition().y + playerH < spriteY + spriteH)) {
			std::cout << "collisionTOP";
			//player.playerSetPosition(currentPositon);
			player.playerSetPosition(sf::Vector2f(playerX, spriteY - playerH));
			//player.move(sf::Vector2f(0, spriteY - playerH - gravity));
			player.setGravityZero();
			player.setCanJump();
			
		}


		
	}


	return 1;
}

int CollissionsDetection::testThread(Player& player) {
	while(1)
		std::cout << "thread\n";
	return 0;
}