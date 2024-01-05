#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "Player.h"
#include "BitmapHandler.h"
#include "CollissionsDetection.h"
#include "Enemy.h"
#include "MapHandler.h"

/// Klasa silnika gry.
/// 
/// Klasa Engine pe³ni rolê silnika gry, zarz¹dzaj¹c g³ówn¹ pêtl¹ gry, obs³uguj¹c
/// wejœcia, aktualizuj¹c stan gry, rysuj¹c obiekty na ekranie, oraz obs³uguj¹c
/// inne aspekty gry.
class Engine {
public:
    /// Metoda zwracaj¹ca instancjê klasy Engine.
    ///
    /// @return Referencja do instancji klasy Engine.
    static Engine& getInstance();
    /// Inicjalizuje silnik gry.
    ///
    /// @param screenWidth Szerokoœæ okna gry.
    /// @param screenHeight Wysokoœæ okna gry.
    /// @param windowTitle Tytu³ okna gry.
    void init(int screenWidth, int screenHeight, const std::string windowTitle);
    /// Inicjalizuje silnik gry u¿ywaj¹cy rêcznie zdefiniowanego podwójnego buforowania.
    ///
    /// @param screenWidth Szerokoœæ okna gry.
    /// @param screenHeight Wysokoœæ okna gry.
    /// @param windowTitle Tytu³ okna gry.
    void init2b(int screenWidth, int screenHeight, const std::string windowTitle);
    /// Ustawia liczbê klatek na sekundê.
    ///
    /// @param fps Liczba klatek na sekundê.
    void setFramesPerSecond(int fps);
    /// Ustawia rozmiar okna gry.
    ///
    /// @param width Szerokoœæ okna gry.
    /// @param height Wysokoœæ okna gry.
    void setWindowSize(int width, int height);
    /// Ustawia tryb pe³noekranowy lub okienkowy.
    ///
    /// @param fullscreen True, jeœli gra ma byæ w trybie pe³noekranowym, False w przeciwnym razie.
    /// @param height Wysokoœæ okna gry.
    void setFullscreen(bool fullscreen);
    /// W³¹cza obs³ugê wejœcia myszy.
    void enableMouseInput();
    /// Obs³uguje wejœcie gracza.
    ///
    /// @param player Referencja do obiektu gracza.
    /// @param bmp Referencja do obiektu BitmapHandler.
    /// @param mapHandler Referencja do obiektu MapHandler.
    /// @param collissionsDetection Referencja do obiektu CollissionsDetection.
    void handleInput(Player& player, BitmapHandler& bmp, MapHandler& mapHandler, CollissionsDetection& collissionsDetection);
    /// Aktualizuje stan gry.
    ///
    /// @param player Referencja do obiektu gracza.
    /// @param bmp Referencja do obiektu BitmapHandler.
    /// @param mapHandler Referencja do obiektu MapHandler.
    /// @param collissionsDetection Referencja do obiektu CollissionsDetection.
    void update(Player& player, BitmapHandler& bmp, MapHandler& mapHandler, CollissionsDetection& collissionsDetection);
    /// Czyœci ekran gry.
    ///
    /// @param color Kolor, którym ma zostaæ wyczyszczony ekran.
   
    void clearScreen(const sf::Color color);
    /// Rysuje obiekty na ekranie.
    void draw();
    /// Wyœwietla zawartoœæ okna gry.
    void display();
    /// Uruchamia g³ówn¹ pêtlê gry.
    void run();
    /// Uruchamia g³ówn¹ pêtlê gry korzystaj¹c z rêcznie zdefiniowanego podwójnego buforowania.
    void run2b();
    /// Zwraca referencjê do obiektu sf::RenderWindow.
    ///
    /// @return Referencja do obiektu sf::RenderWindow.
    sf::RenderWindow& getWindow();
    /// Aktualizuje licznik klatek na sekundê.
    void frameCounterUpdate();
    /// Zwraca liczbê klatek na sekundê.
    /// @return Liczba klatek na sekundê.
    int getFps();
    

private:
    /// Okno gry.
    sf::RenderWindow window;
    /// Bufor renderowania 1.
    sf::RenderTexture buffer1;
    /// Bufor renderowania 2.
    sf::RenderTexture buffer2;
    /// Flaga, czy silnik zosta³ zainicjalizowany.
    bool initialized;
    /// Unikalny wskaŸnik na obiekt Projectile. 
    std::unique_ptr<Projectile> projectile;
    /// Wektor obiektów Projectile.
    std::vector<Projectile> projectiles;
    ///  Wektor wskaŸników na obiekty Enemy.
    std::vector<Enemy*> enemies;
    std::vector<Cherry*> cherries;
    /// Konstruktor klasy Engine.
    Engine();
    /// Destruktor klasy Engine.
    ~Engine();
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    /// Loguje b³¹d.
    /// 
    /// @param errorMessage Treœæ komunikatu b³êdu.
    void logError(const std::string errorMessage);
    /// Loguje informacjê.
    ///
    /// @param infoMessage Treœæ komunikatu informacyjnego.
    void logInfo(const std::string infoMessage);
    /// Licznik klatek.
    int frameCount;
    ///Liczba klatek na sekundê.
    int fps;
    /// Zegar do mierzenia czasu miêdzy klatkami
    sf::Clock frameClock;
    
};