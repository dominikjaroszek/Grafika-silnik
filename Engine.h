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


class Engine {
public:
    static Engine& getInstance();

    void init(int screenWidth, int screenHeight, const std::string windowTitle);
    //void init2b(int screenWidth, int screenHeight, const std::string windowTitle);
    void setFramesPerSecond(int fps);
    void setWindowSize(int width, int height);
    void setFullscreen(bool fullscreen);
    void enableMouseInput();
    void handleInput(Player& player, BitmapHandler& bmp, CollissionsDetection &collissionsDetection);
    void update(Player& player, BitmapHandler& bmp, MapHandler& mapHandler, CollissionsDetection& collissionsDetection);
    void clearScreen(const sf::Color color);
    void draw();
    void display();
    void run();
    //void run2b();
    sf::RenderWindow& getWindow();
    

private:
    sf::RenderWindow window;
    sf::RenderTexture buffer1;
    sf::RenderTexture buffer2;
    bool initialized;
    std::unique_ptr<Projectile> projectile;
    std::vector<Projectile> projectiles;
    std::vector<Enemy*> enemies;

    Engine();
    ~Engine();
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    void logError(const std::string errorMessage);
    void logInfo(const std::string infoMessage);
};