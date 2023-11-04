#include "CollissionsDetection.h"
#include <iostream>


CollissionsDetection::CollissionsDetection(BitmapHandler& bitmap) :bitmap(bitmap) {}


int CollissionsDetection::playerCollisions(Player& player) {
	
	float playerX = player.playerPosition().x;
	float playerY = player.playerPosition().y;
	float playerW = player.playerSize().width;
	float playerH = player.playerSize().height;

	float textureX = bitmap.getSize().getPosition().x;
	float textureY = bitmap.getSize().getPosition().y;
	float textureW = bitmap.getSize().width;
	float textureH = bitmap.getSize().height;

	/*if (player.playerSize().intersects(bitmap.getSize())) {
		return true;
		std::cout << "AAAAAA";
	}*/

	//if (player.playerPosition().x - 50 < bitmap.getSize().getPosition().x + bitmap.getSize().width &&
	//	player.playerPosition().x + player.playerSize().width + 50 > bitmap.getSize().getPosition().x &&
	//	player.playerPosition().y < bitmap.getSize().getPosition().y + bitmap.getSize().height &&
	//	player.playerPosition().y + player.playerSize().height > bitmap.getSize().getPosition().y) {
	//	// Collision detected, do something
	//	return 1;
	//}

	//if (player.playerPosition().x + player.playerSize().width + 50 > bitmap.getSize().getPosition().x &&
	//	//player.playerPosition().x < bitmap.getSize().getPosition().x + bitmap.getSize().width &&
	//	player.playerPosition().y < bitmap.getSize().getPosition().y + bitmap.getSize().height &&
	//	player.playerPosition().y + player.playerSize().height > bitmap.getSize().getPosition().y) {
	//	// Collision detected, do something
	//	return 2;
	//}

	/*if (player.playerPosition().x + player.playerSize().width + 5 > bitmap.getSize().left) {
		return 1;
	}

	if (player.playerPosition().x - 5 < bitmap.getSize().getPosition().x + bitmap.getSize().width) {
		return 2;
	}

	if (player.playerPosition().y - 51 > bitmap.getSize().getPosition().y + bitmap.getSize().height) {
		return 3;
	}

	if (player.playerPosition().y+player.playerSize().height + 1 > bitmap.getSize().getPosition().y) {
		return 4;
	}

	return 5;
	
	player.playerPosition().y > bitmap.getSize().getPosition().y + bitmap.getSize().height  player.playerPosition().y + player.playerSize().height > bitmap.getSize().getPosition().y)*/
	if (playerY + playerH +1> textureY && (playerX > textureX && playerX < textureX + textureW)) {

		return 3;
	}
	if (playerX+ playerW/2 + 5 > textureX && playerX < textureX + textureW && (playerY<textureY+textureH && playerY+playerH>textureY)) {
		
		return 1;
	}
	
	if (playerX - 5 < textureX+textureW+playerW/2 && playerX > textureX && (playerY<textureY+textureH && playerY+playerH>textureY)) {
		
		return 2;
	}

	

	/*if (playerX+ playerW - 5 > textureX + textureW && (playerY+playerH>textureY || playerY<textureY+textureH)) {
		return 1;
	}*/

	//if (playerX + playerW - 5 < textureX + textureW) {
	//	return 2;
	//}
}