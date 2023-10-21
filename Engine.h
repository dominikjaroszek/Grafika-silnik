#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

class Engine {
public:
    static Engine& getInstance();


    void init(int screenWidth, int screenHeight, std::string windowTitle);
    void setFramesPerSecond(int fps);

    void setWindowSize(int width, int height);

    void setFullscreen(bool fullscreen);
    void enableMouseInput();
    void handleInput();

    void update();

    void clearScreen(const sf::Color& color);

    void draw();

    void display();

    void run();
    sf::RenderWindow& GetWindow();

private:
    sf::RenderWindow window;
    bool initialized;


    Engine();

    ~Engine();


    void logError(const std::string& errorMessage);


    void logInfo(const std::string& infoMessage); 
};