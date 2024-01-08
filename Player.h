#pragma once
#include "UpdatableObject.h"
#include "Projectile.h"
#include "SpriteObject.h"

/// Klasa reprezentuj¹ca gracza w grze.
/// 
/// Klasa Player dziedziczy po klasie UpdatableObject, co oznacza, ¿e jest to obiekt gry, który mo¿e byæ zaktualizowany w trakcie dzia³ania gry.Klasa ta implementuje
/// metody pozwalaj¹ce na zarz¹dzanie graczem, takie jak ruch, skok, aktualizacja animacji.
class Player : public UpdatableObject, public SpriteObject{
public:
	/// Konstruktor klasy Player.
	///
	/// @param window Referencja do obiektu sf::RenderWindow, w którym gracz jest renderowany.
	/// @param position Pocz¹tkowa pozycja gracza.
	Player(sf::RenderWindow& window, sf::Vector2f position);
	//void init(sf::RenderWindow& window, sf::Vector2f position);
	/// Metoda aktualizuj¹ca stan gracza.
	///
	/// Aktualizuje pozycjê gracza, obs³uguje ruch, skok, grawitacjê oraz animacje.
	void update() override;
	/// Metoda przemieszczaj¹ca gracza.
	///
	/// Przesuwa gracza o podany wektor przemieszczenia. Ustala równie¿ kierunek i aktualizuje animacjê chodu.
	/// @param move Wektor przemieszczenia gracza.
	void move(sf::Vector2f move);
	/// Metoda zwracaj¹ca pozycjê gracza.
	///
	/// @return Pozycja gracza jako sf::Vector2f.
	sf::Vector2f playerPosition();
	/// Metoda zwracaj¹ca rozmiar gracza.
	///
	/// @return Rozmiar gracza jako sf::FloatRect.
	sf::FloatRect playerSize();
	/// Metoda wykonuj¹ca skok gracza.
	void jump();
	/// Metoda zwracaj¹ca kierunek, w którym patrzy gracz.
	///
	/// @return -1 dla lewo, 1 dla prawo.
	int getDirection();
	/// Metoda sprawdzaj¹ca, czy gracz porusza siê w poziomie.
	///
	/// @return True, jeœli gracz porusza siê w poziomie, False w przeciwnym razie.
	bool isMovingHorizontal();
	/// Metoda ustawiaj¹ca pozycjê gracza na poprzedni¹.
	void playerSetPosition();
	/// Metoda ustawiaj¹ca konkretn¹ pozycjê gracza.
	///
	/// @param pos Nowa pozycja gracza jako sf::Vector2f.
	void playerSetPosition(sf::Vector2f pos);
	/// Ostatnia pozycja gracza.
	sf::Vector2f lastPosition;
	/// Zmienna okreœlaj¹ca, czy dosz³o do kolizji z górn¹ krawêdzi¹ obiektu.
	bool collisionTopY;
	/// Zmienna okreœlaj¹ca, czy dosz³o do kolizji z doln¹ krawêdzi¹ obiektu
	bool collisionBottomY;
	/// Zmienna okreœlaj¹ca, czy obiekt aktualnie wykonuje skok.
	bool isJumping;
	/// Metoda zwracaj¹ca indeks aktualnie wybranej mapy.
	///
	/// @return Indeks aktualnej mapy.
	int getMapIndex();
	/// Metoda ustawiaj¹ca prêdkoœæ grawitacyjn¹ gracza na zero.
	void setGravityZero();
	/// Metoda auktualizuj¹ca Y gracza.
	void updatePlayerY();
	/// Metoda zwracaj¹ca prêdkoœæ grawitacyjn¹ gracza.
	///
	/// @return Aktualna prêdkoœæ grawitacyjna gracza.
	float getGravitySpeed();
	/// Metoda ustawiaj¹ca mo¿liwoœæ wykonania skoku.
	void setCanJump();
	/// Przes³oniêcie metody z klasy AnimatedObject.
	void animate() override;
	/// Przes³oniêcie metody z klasy DrawableObject.
	void draw() override;
	/// Metoda zwracaj¹ca sprite gracza.
	sf::Sprite getSprite();
	
	
	
private:
	/// Obiekt sf::Sprite reprezentuj¹cy gracza.
	sf::Sprite sprite;
	/// Referencja do obiektu sf::RenderWindow, w którym gracz jest renderowany.
	sf::RenderWindow& window;
	/// Obiekt sf::Texture przechowuj¹cy teksturê gracza.
	sf::Texture texture;
	/// Prêdkoœæ grawitacyjna gracza.
	int gravity_speed;
	///Pozycja dolnej krawêdzi gracza.
	float bottomY;
	///Indeks aktualnej klatki animacji spoczynku.
	float IdleAnimationIndex;
	/// Indeks aktualnej klatki animacji chodu.
	float WalkAnimationIndex;
	/// Indeks aktualnej klatki animacji skoku.
	float JumpAnimationIndex;
	/// Okreœla, czy gracz porusza siê w poziomie.
	bool isMovingX;
	/// Okreœla, czy gracz porusza siê w pionie.
	bool isMovingY;
	/// Poprzednia pozycja gracza.
	sf::Vector2f lastPos;
	/// Metoda aktualizuj¹ca animacjê spoczynku gracza.
	void updateAnimationIdle();
	/// Metoda aktualizuj¹ca animacjê skoku gracza.
	void updateAnimationJump();
	/// Metoda aktualizuj¹ca animacjê chodzenia gracza.
	void updateAnimationWalk();
	/// Indeks aktualnej mapy.
	int mapIndex;
	/// Okreœla, czy gracz mo¿e skakaæ.
	bool canJump;
	
};

