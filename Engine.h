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
/// Klasa Engine pe�ni rol� silnika gry, zarz�dzaj�c g��wn� p�tl� gry, obs�uguj�c
/// wej�cia, aktualizuj�c stan gry, rysuj�c obiekty na ekranie, oraz obs�uguj�c
/// inne aspekty gry.
class Engine {
public:
    /// Metoda zwracaj�ca instancj� klasy Engine.
    ///
    /// @return Referencja do instancji klasy Engine.
    static Engine& getInstance();
    /// Inicjalizuje silnik gry.
    ///
    /// @param screenWidth Szeroko�� okna gry.
    /// @param screenHeight Wysoko�� okna gry.
    /// @param windowTitle Tytu� okna gry.
    void init(int screenWidth, int screenHeight, const std::string windowTitle);
    /// Inicjalizuje silnik gry u�ywaj�cy r�cznie zdefiniowanego podw�jnego buforowania.
    ///
    /// @param screenWidth Szeroko�� okna gry.
    /// @param screenHeight Wysoko�� okna gry.
    /// @param windowTitle Tytu� okna gry.
    void init2b(int screenWidth, int screenHeight, const std::string windowTitle);
    /// Ustawia liczb� klatek na sekund�.
    ///
    /// @param fps Liczba klatek na sekund�.
    void setFramesPerSecond(int fps);
    /// Ustawia rozmiar okna gry.
    ///
    /// @param width Szeroko�� okna gry.
    /// @param height Wysoko�� okna gry.
    void setWindowSize(int width, int height);
    /// Ustawia tryb pe�noekranowy lub okienkowy.
    ///
    /// @param fullscreen True, je�li gra ma by� w trybie pe�noekranowym, False w przeciwnym razie.
    /// @param height Wysoko�� okna gry.
    void setFullscreen(bool fullscreen);
    /// W��cza obs�ug� wej�cia myszy.
    void enableMouseInput();
    /// Obs�uguje wej�cie gracza.
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
    /// Czy�ci ekran gry.
    ///
    /// @param color Kolor, kt�rym ma zosta� wyczyszczony ekran.
   
    void clearScreen(const sf::Color color);
    /// Rysuje obiekty na ekranie.
    void draw();
    /// Wy�wietla zawarto�� okna gry.
    void display();
    /// Uruchamia g��wn� p�tl� gry.
    void run();
    /// Uruchamia g��wn� p�tl� gry korzystaj�c z r�cznie zdefiniowanego podw�jnego buforowania.
    void run2b();
    /// Zwraca referencj� do obiektu sf::RenderWindow.
    ///
    /// @return Referencja do obiektu sf::RenderWindow.
    sf::RenderWindow& getWindow();
    /// Aktualizuje licznik klatek na sekund�.
    void frameCounterUpdate();
    /// Zwraca liczb� klatek na sekund�.
    /// @return Liczba klatek na sekund�.
    int getFps();
    

private:
    /// Okno gry.
    sf::RenderWindow window;
    /// Bufor renderowania 1.
    sf::RenderTexture buffer1;
    /// Bufor renderowania 2.
    sf::RenderTexture buffer2;
    /// Flaga, czy silnik zosta� zainicjalizowany.
    bool initialized;
    /// Unikalny wska�nik na obiekt Projectile. 
    std::unique_ptr<Projectile> projectile;
    /// Wektor obiekt�w Projectile.
    std::vector<Projectile> projectiles;
    ///  Wektor wska�nik�w na obiekty Enemy.
    std::vector<Enemy*> enemies;
    std::vector<Cherry*> cherries;
    /// Konstruktor klasy Engine.
    Engine();
    /// Destruktor klasy Engine.
    ~Engine();
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    /// Loguje b��d.
    /// 
    /// @param errorMessage Tre�� komunikatu b��du.
    void logError(const std::string errorMessage);
    /// Loguje informacj�.
    ///
    /// @param infoMessage Tre�� komunikatu informacyjnego.
    void logInfo(const std::string infoMessage);
    /// Licznik klatek.
    int frameCount;
    ///Liczba klatek na sekund�.
    int fps;
    /// Zegar do mierzenia czasu mi�dzy klatkami
    sf::Clock frameClock;
    
};