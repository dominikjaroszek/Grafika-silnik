#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "Player.h"
#include <memory>



Engine::Engine() : initialized(false) {
    
}

Engine::~Engine() {
    
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

void Engine::handleInput(Player& player) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sf::Vector2f mv(5.0f, 0.0f);
        player.move(mv);
        player.moveAnimation();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sf::Vector2f mv(-5.0f, 0.0f);
        player.move(mv);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.jump();
    }

  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        if (!projectile) {
            projectile = std::make_unique<Projectile>(window, player.playerPosition());
        }

        if (projectile->projectableReady())
            projectile = std::make_unique<Projectile>(window, player.playerPosition());

    }

    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (projectiles.size() < 52) {
            Projectile pro(window, player.playerPosition());
            projectiles.push_back(pro);
        }
       
        }
    */
 
}


void Engine::update(Player& player) {
    
    player.update();

    
    
    if (projectile)
        projectile->update();
    

    

   
   /*
    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i].update();

   }

    */
   

}

void Engine::clearScreen(const sf::Color color) {
    window.clear(color);
}

void Engine::draw() {
   
    PrimitiveRenderer primitiveRenderer(window);
    Point2D point, start, stop;

    
    


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
   // primitiveRenderer.drawLineInstrukcja(linePoint5, linePoint6, lineColor3);

    point.setCoordinates(50.0, 50.0);
    point.draw(primitiveRenderer, sf::Color::Magenta);

    start.setCoordinates(10.0, 10.0);
    stop.setCoordinates(500.0, 200.0);

    LineSegment line(start,stop);
    line.draw(primitiveRenderer, sf::Color::Cyan, true);


    std::vector<Point2D> points;
   Point2D point1 = Point2D(0.0f, 0.0f);
   Point2D point2 = Point2D(500.0f, 600.0f);
   Point2D point3 = Point2D(400.0f, 400.0f);
       
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);

    primitiveRenderer.brokeLine(points, sf::Color::Green, 0);

    std::vector<sf::Vector2f> invalidPolygonPoints = {
    sf::Vector2f(100.0f, 100.0f),
    sf::Vector2f(200.0f, 100.0f),
    sf::Vector2f(200.0f, 200.0f),
    sf::Vector2f(100.0f, 150.0f),
    sf::Vector2f(300.0f, 110.0f)
    };
    

    std::vector<LineSegment> lines;

    Point2D start1(100.0f, 100.0f);
    Point2D start2(200.0f, 100.0f);
    Point2D start3(200.0f, 200.0f);
    Point2D start4(100.0f, 150.0f);

    lines.push_back(LineSegment(start1, start2));
    lines.push_back(LineSegment(start2, start3));
    lines.push_back(LineSegment(start3, start4));
    lines.push_back(LineSegment(start4, start1));

    /*std::vector<LineSegment> lines;

    Point2D start1(100.0f, 100.0f);
    Point2D start2(200.0f, 200.0f);

    Point2D start3(100.0f, 200.0f);
    Point2D start4(200.0f, 100.0f);

    lines.push_back(LineSegment(start1, start2));
    lines.push_back(LineSegment(start3, start4));*/

    primitiveRenderer.drawPolygon(lines, sf::Color::Green);
    //primitiveRenderer.drawLine(sf::Vector2f(200.0f, 100.0f),)
   // primitiveRenderer.drawPolygon(invalidPolygonPoints, sf::Color::Green);
    
    //primitiveRenderer.brokeLine(invalidPolygonPoints, sf::Color::Green, 0);
    

    sf::Vector2f f1(0.0f, 500.0f);
    sf::Vector2f f2(800.0f, 500.0f);
    primitiveRenderer.drawLine(f1, f2, sf::Color::Green);
    


}


void Engine::display() {
    window.display();
    window.clear();

}

void Engine::run() {
    sf::Clock clock;
    float deltaTime = 0.0f;
    
    sf::Vector2f position(100.0f, 100.0f);

    Player player(window, position);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
     
        sf::Time elapsed = clock.getElapsedTime();

        



        deltaTime = clock.restart().asSeconds();

        handleInput(player);
        update(player);
        draw();
        display();
       
    }
}


sf::RenderWindow& Engine::getWindow() {
    return window;
}

void Engine::logError(const std::string errorMessage) {
    
    std::ofstream errorLog("error_log.txt", std::ios::app);
    errorLog << "Error: " << errorMessage << std::endl;
    errorLog.close();
}

void Engine::logInfo(const std::string infoMessage) {
    
    std::ofstream diagnosticLog("diagnostic_log.txt", std::ios::app);
    diagnosticLog << "Info: " << infoMessage << std::endl;
    diagnosticLog.close();
}
