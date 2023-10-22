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

void Engine::init(int screenWidth, int screenHeight, const std::string windowTitle) {
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

void Engine::clearScreen(const sf::Color color) {
    window.clear(color);
}

void Engine::draw() {
    // Utwórz instancjê klasy PrimitiveRenderer, przekazuj¹c referencjê do sf::RenderWindow
    PrimitiveRenderer primitiveRenderer(window);
    Point2D point, start, stop;
    

    // Teraz mo¿esz u¿yæ funkcji rysuj¹cych z klasy PrimitiveRenderer
    sf::Vector2f position(100.0f, 100.0f);
    sf::Vector2f size(50.0f, 50.0f);
    sf::Color color(sf::Color::Red);

    primitiveRenderer.drawRectangle(position, size, color);

    sf::Vector2f circlePosition(200.0f, 200.0f);
    float circleRadius = 30.0f;
    sf::Color circleColor(sf::Color::Blue);

    primitiveRenderer.drawCircle(circlePosition, circleRadius, circleColor);

    sf::Vector2f linePoint1(300.0f, 300.0f);
    sf::Vector2f linePoint2(400.0f, 400.0f);
    sf::Color lineColor(sf::Color::Green);

    primitiveRenderer.drawLine(linePoint1, linePoint2, lineColor);

    sf::Vector2f linePoint5(0.0f, 0.0f);
    sf::Vector2f linePoint6(500.0f, 600.0f);
    sf::Color lineColor3(sf::Color::Red);
    primitiveRenderer.drawLineInstrukcja(linePoint5, linePoint6, lineColor3);

    point.setCoordinates(50.0, 50.0);
    point.draw(primitiveRenderer, sf::Color::Magenta);

    start.setCoordinates(10.0, 10.0);
    stop.setCoordinates(500.0, 200.0);

    LineSegment line(start,stop);
    line.draw(primitiveRenderer, sf::Color::Cyan, true);




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
        draw();
        display();
    }
    
}

sf::RenderWindow& Engine::getWindow() {
    return window;
}

void Engine::logError(const std::string errorMessage) {
    // Obs³uga b³êdów
    std::ofstream errorLog("error_log.txt", std::ios::app);
    errorLog << "Error: " << errorMessage << std::endl;
    errorLog.close();
}

void Engine::logInfo(const std::string infoMessage) {
    // Logowanie informacji diagnostycznych
    std::ofstream diagnosticLog("diagnostic_log.txt", std::ios::app);
    diagnosticLog << "Info: " << infoMessage << std::endl;
    diagnosticLog.close();
}
