#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "Player.h"
#include <memory>

#include <thread>



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

void Engine::handleInput(Player& player, BitmapHandler& bmp,MapHandler &mapHandler, CollissionsDetection &collissionsDetection) {

  
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (player.playerPosition().x + 50 > 800 && enemies.size()>0)
            player.playerSetPosition(sf::Vector2f(750, player.playerPosition().y));

        sf::Vector2f mv(5.0f, 0.0f);
        if (collissionsDetection.playerCollisions(player, mv) != 1)
            player.move(mv);
       
    }
        
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (player.playerPosition().x - 50 < 0 && player.getMapIndex() == 0)
            player.playerSetPosition(sf::Vector2f(50,player.playerPosition().y));

        sf::Vector2f mv(-5.0f, 0.0f);

        if(collissionsDetection.playerCollisions(player, mv) != 1)
             player.move(mv);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      
            player.jump();
          //  player.playerSetPosition();
        
    }

  


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        int direction = player.getDirection();

        if (!projectile) {
            projectile = std::make_unique<Projectile>(window, player.playerPosition(), direction, player.isMovingHorizontal());
        }

        if (projectile->projectableReady())
            projectile = std::make_unique<Projectile>(window, player.playerPosition(), direction, player.isMovingHorizontal());

    }

 
 
}


void Engine::update(Player& player, BitmapHandler &bmp, MapHandler &mapHandler, CollissionsDetection& collissionsDetection) {
    

    player.lastPosition = player.playerPosition();
    bmp.renderBitmap();
    mapHandler.setMapIndex(player.getMapIndex());
    mapHandler.renderBitmap();
    collissionsDetection.setPlatformSprites(mapHandler.getPlatformSprites());

    
    
    collissionsDetection.playerCollisions(player);

    /*
    std::thread collisionThread([&]() {

        collissionsDetection.testThread(player);
        });
    collisionThread.join();
    */
    

    player.update();
    

    
    if (projectile)
        projectile->update();

    
      enemies = mapHandler.getEnemies();
    // std::cout << "\n" << enemies.size() <<"\n";
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->update();
    }
  

    
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->getPosition().x < player.playerPosition().x)
            mapHandler.removeEnemy(i);
        // kolizja here
    }
    
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
    line.draw(primitiveRenderer, sf::Color::Magenta, true);
    line.translate(30, 80);
    line.draw(primitiveRenderer, sf::Color::Magenta, true);
    //line.rotate(30);
    line.scale(3);
    line.draw(primitiveRenderer, sf::Color::Magenta, false);
    line.rotate(0.1f);
    line.draw(primitiveRenderer, sf::Color::Magenta, false);
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
    Point2D start2(200.0f, 150.0f);
    Point2D start3(200.0f, 160.0f);
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
    

    sf::Vector2f f1(0.0f, 550.0f);
    sf::Vector2f f2(800.0f, 550.0f);
    //primitiveRenderer.drawLine(f1, f2, sf::Color::Green);
    LineSegment chery(start1, start2);
    chery.drawCherry(primitiveRenderer, sf::Vector2f(400.0f, 300.0f));
    chery.drawCherry(primitiveRenderer, sf::Vector2f(500.0f, 400.0f));
    
   // sf::Vector2f c(600.0f, 200.0f);
    //primitiveRenderer.drawCircleInstrukcja(c, 10, sf::Color::Cyan);
    //primitiveRenderer.floodFill(c, sf::Color::Red);
    
    

}


void Engine::display() {
    window.display();
    window.clear();

}

void Engine::run() {
    sf::Clock clock;
    float deltaTime = 0.0f;
    const float fixedTimeStep = 1.0f / 60.0f;

    BitmapHandler bitmapHandler(window);
    MapHandler mapHandler(window);

    sf::Vector2f position(100.0f, 500.0f);
    Player player(window, position);

    CollissionsDetection collissionsDetection;
  
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        deltaTime += clock.restart().asSeconds(); 
       
  
        
        
        while (deltaTime >= fixedTimeStep) {
            frameCounterUpdate();
            handleInput(player, bitmapHandler, mapHandler, collissionsDetection);
            update(player, bitmapHandler, mapHandler, collissionsDetection);
            deltaTime -= fixedTimeStep;
            if (player.getMapIndex() == 0) {
                  draw();
                display();
            }
            else {
                display();
                   draw();
            }
        }
        
        
        std::cout << getFps() << std::endl;
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

void Engine::frameCounterUpdate(){
    frameCount++;
    if (frameClock.getElapsedTime().asSeconds() >= 1.0f) {
        fps = frameCount;
        frameCount = 0;
        frameClock.restart();
    }

}

int Engine::getFps(){
    return fps;
}