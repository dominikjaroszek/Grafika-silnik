#pragma once
#include "UpdatableObject.h"
#include "Projectile.h"

/// Klasa reprezentuj�ca gracza w grze.
/// 
/// Klasa Player dziedziczy po klasie UpdatableObject, co oznacza, �e jest to obiekt gry, kt�ry mo�e by� zaktualizowany w trakcie dzia�ania gry.Klasa ta implementuje
/// metody pozwalaj�ce na zarz�dzanie graczem, takie jak ruch, skok, aktualizacja animacji.
class Player : public UpdatableObject{
public:
	/// Konstruktor klasy Player.
	///
	/// @param window Referencja do obiektu sf::RenderWindow, w kt�rym gracz jest renderowany.
	/// @param position Pocz�tkowa pozycja gracza.
	Player(sf::RenderWindow& window, sf::Vector2f position);
	//void init(sf::RenderWindow& window, sf::Vector2f position);
	/// Metoda aktualizuj�ca stan gracza.
	///
	/// Aktualizuje pozycj� gracza, obs�uguje ruch, skok, grawitacj� oraz animacje.
	
	void update() override;

	/// Metoda przemieszczaj�ca gracza.
	///
	/// Przesuwa gracza o podany wektor przemieszczenia. Ustala r�wnie� kierunek i aktualizuje animacj� chodu.
	/// @param move Wektor przemieszczenia gracza.
	void move(sf::Vector2f move);
	/// Metoda zwracaj�ca pozycj� gracza.
	///
	/// @return Pozycja gracza jako sf::Vector2f.
	sf::Vector2f playerPosition();
	/// Metoda zwracaj�ca rozmiar gracza.
	///
	/// @return Rozmiar gracza jako sf::FloatRect.
	sf::FloatRect playerSize();
	/// Metoda wykonuj�ca skok gracza.
	void jump();
	/// Metoda zwracaj�ca kierunek, w kt�rym patrzy gracz.
	///
	/// @return -1 dla lewo, 1 dla prawo.
	int getDirection();
	/// Metoda sprawdzaj�ca, czy gracz porusza si� w poziomie.
	///
	/// @return True, je�li gracz porusza si� w poziomie, False w przeciwnym razie.
	bool isMovingHorizontal();
	/// Metoda ustawiaj�ca pozycj� gracza na poprzedni�.
	void playerSetPosition();
	/// Metoda ustawiaj�ca konkretn� pozycj� gracza.
	///
	/// @param pos Nowa pozycja gracza jako sf::Vector2f.
	void playerSetPosition(sf::Vector2f pos);
	sf::Vector2f lastPosition;
	bool collisionTopY;
	bool collisionBottomY;
	bool isJumping;
	int getMapIndex();
	/// Metoda ustawiaj�ca pr�dko�� grawitacyjn� gracza na zero.
	void setGravityZero();
	void updatePlayerY();
	/// Metoda zwracaj�ca pr�dko�� grawitacyjn� gracza.
	///
	/// @return Aktualna pr�dko�� grawitacyjna gracza.
	float getGravitySpeed();
	//Metoda ustawiaj�ca mo�liwo�� wykonania skoku.
	void setCanJump();
	

	
	
	
private:
	/// Obiekt sf::Sprite reprezentuj�cy gracza.
	sf::Sprite sprite;
	/// Referencja do obiektu sf::RenderWindow, w kt�rym gracz jest renderowany.
	sf::RenderWindow& window;
	/// Obiekt sf::Texture przechowuj�cy tekstur� gracza.
	sf::Texture texture;
	/// Pr�dko�� grawitacyjna gracza.
	int gravity_speed;
	///Pozycja dolnej kraw�dzi gracza.
	float bottomY;
	float IdleAnimationIndex;
	/// Indeks aktualnej klatki animacji chodu.
	float WalkAnimationIndex;
	/// Indeks aktualnej klatki animacji skoku.
	float JumpAnimationIndex;
	/// Okre�la, czy gracz porusza si� w poziomie.
	bool isMovingX;
	/// Okre�la, czy gracz porusza si� w pionie.
	bool isMovingY;
	/// Poprzednia pozycja gracza.
	sf::Vector2f lastPos;
	/// 
	void updateAnimationIdle();
	void updateAnimationJump();
	void updateAnimationWalk();
	/// Indeks aktualnej mapy.
	int mapIndex;
	/// Okre�la, czy gracz mo�e skaka�.
	bool canJump;
	
};

