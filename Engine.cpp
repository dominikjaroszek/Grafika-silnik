#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

Engine::Engine() : initialized(false) {
    // Inicjacja konstruktora (np. inicjalizacja zmiennych)
}

Engine::~Engine() {
    // Deinicjacja (np. sprz¹tanie pamiêci, zamkniêcie plików itp.)
}

Engine& Engine::getInstance() {
    static Engine instance;
    return instance;
}

void Engine::init(int screenWidth, int screenHeight, const std::string& windowTitle) {
    if (!initialized) {
        window.create(sf::VideoMode(screenWidth, screenHeight), windowTitle);
        window.setFramerateLimit(60);
        initialized = true;
    }
}

void Engine::setFramesPerSecond(int fps) {
    window.setFramerateLimit(fps);
}

void Engine::setWindowSize(int width, int height) {
    window.setSize(sf::Vector2u(width, height));
}

void Engine::setFullscreen(bool fullscreen) {
    if (fullscreen) {
        window.create(sf::VideoMode::getFullscreenModes()[0], "Fullscreen");
    }
    else {
        window.create(sf::VideoMode(window.getSize().x, window.getSize().y), "Windowed");
    }
}

void Engine::enableMouseInput() {
    window.setMouseCursorVisible(true);
    window.setMouseCursorGrabbed(true);
    sf::Cursor cursor;
    if (cursor.loadFromSystem(sf::Cursor::Arrow)) {
        window.setMouseCursor(cursor);
    }
}

void Engine::handleInput() {
    // Obs³uga klawiatury i myszy
}

void Engine::update() {
    // Aktualizacja logiki gry
}

void Engine::clearScreen(const sf::Color& color) {
    window.clear(color);
}

void Engine::draw() {
    // Rysowanie obiektów gry
    PrimitiveRenderer primitiveRender(window); // Przyk³ad u¿ycia PrimitiveRenderer
}

void Engine::display() {
    window.display();
}

void Engine::run() {
    sf::Clock clock;
    float deltaTime = 0.0f;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        deltaTime = clock.restart().asSeconds();
        handleInput();
        update();
        clearScreen(sf::Color::Black);
        draw();
        display();
    }
}

sf::RenderWindow& Engine::getWindow() {
    return window;
}

void Engine::logError(const std::string& errorMessage) {
    // Obs³uga b³êdów
    std::ofstream errorLog("error_log.txt", std::ios::app);
    errorLog << "Error: " << errorMessage << std::endl;
    errorLog.close();
}

void Engine::logInfo(const std::string& infoMessage) {
    // Logowanie informacji diagnostycznych
    std::ofstream diagnosticLog("diagnostic_log.txt", std::ios::app);
    diagnosticLog << "Info: " << infoMessage << std::endl;
    diagnosticLog.close();
}



KiedyFotkaDlaMnie
