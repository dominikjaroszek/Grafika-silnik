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
        if (player.playerPosition().x + 50 > 800 && (enemies.size()>0 || cherries.size()>0 || mapHandler.getMapIndex()>4))
            player.playerSetPosition(sf::Vector2f(750, player.playerPosition().y));

        sf::Vector2f mv(5.0f, 0.0f);
        if (collissionsDetection.playerCollisions(player, mv) != 1)
            player.move(mv);
       
    }
        
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (player.playerPosition().x - 50 < 0 && (player.getMapIndex() == 0 ||enemies.size() > 0 || cherries.size() > 0))
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        sf::Texture texture;
        window.display();
        texture.create(window.getSize().x, window.getSize().y);
        texture.update(window);
        BitmapHandler::saveToFile("screenshot.png", texture);
    }
 
 
}


void Engine::update(Player& player, BitmapHandler &bmp, MapHandler &mapHandler, CollissionsDetection& collissionsDetection) {
    
    

    player.lastPosition = player.playerPosition();
    bmp.renderBitmap();
    int lastMapIndex = mapHandler.getMapIndex();
    
    mapHandler.setMapIndex(player.getMapIndex());
    mapHandler.renderBitmap();
    collissionsDetection.setPlatformSprites(mapHandler.getPlatformSprites());

    if (lastMapIndex != player.getMapIndex())
        projectile.reset();
    
    collissionsDetection.playerCollisions(player);

    player.update();
    
    
    if (projectile)
        projectile->update();
    
    

    
      enemies = mapHandler.getEnemies();
    // std::cout << "\n" << enemies.size() <<"\n";
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->update();

        if (player.getSprite().getGlobalBounds().intersects(enemies[i]->getSprite().getGlobalBounds())) {
            mapHandler.resetScore();
            Audio::playAttacked();
        }
    }
  

    
    for (int i = 0; i < enemies.size(); i++) {
        if (projectile) {
            if (enemies[i]->getSprite().getGlobalBounds().intersects(projectile->getSprite().getGlobalBounds())) {
                mapHandler.removeEnemy(i);
                projectile.reset();
                Audio::playHit();
            }
        }
    }

    cherries = mapHandler.getCherry();
    for (int i = 0; i < cherries.size(); i++) {
        cherries[i]->update();
    }
    for (int i = 0; i < cherries.size(); i++) {
        sf::Sprite tmp = cherries[i]->getSprite();
        if (tmp.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
            mapHandler.removeCherry(i);
            mapHandler.addScore();
            Audio::playCherry();
        }
        
    }

    if (mapHandler.getMapIndex() >4) {
        mapHandler.renderEndingScreen();
    }

    
}

void Engine::clearScreen(const sf::Color color) {
    window.clear(color);
}

void Engine::draw() {
   
    PrimitiveRenderer primitiveRenderer(window);
  
    primitiveRenderer.drawCherry(sf::Vector2f(320.0f, 370.0f));
    primitiveRenderer.drawTree(sf::Vector2f(600.0f, 350.0f));
    
    BitmapHandler::drawFromFile(window, "MapAssets/nwm.png", 580, 0, 0.2, 0.2);
    
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
    Audio::playTheme();
  
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        deltaTime += clock.restart().asSeconds(); 
      
        while (deltaTime >= fixedTimeStep) {
            frameCounterUpdate();
            display();
            handleInput(player, bitmapHandler, mapHandler, collissionsDetection);
            update(player, bitmapHandler, mapHandler, collissionsDetection);
            deltaTime -= fixedTimeStep;
            
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


void Engine::init2b(int screenwidth, int screenheight, const std::string windowtitle) {
    if (!initialized) {
        window.create(sf::VideoMode(screenwidth, screenheight), windowtitle);
        buffer1.create(screenwidth, screenheight);
        buffer2.create(screenwidth, screenheight);
        window.setFramerateLimit(60);
        initialized = true;
    }
}

void Engine::run2b() {
    sf::Clock clock;
    float deltaTime = 0.0f;
    bool usingBuffer1 = true;
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        deltaTime = clock.restart().asSeconds();
        
        if (usingBuffer1) {
            buffer1.clear();
            sf::Vector2f position(100.0f, 100.0f);
            sf::Vector2f size(50.0f, 50.0f);
            sf::Color color(sf::Color::Red);
            sf::RectangleShape rectangle(size);
            rectangle.setPosition(position);
            rectangle.setFillColor(color);
            buffer1.draw(rectangle);
        } else {
            buffer2.clear();
            sf::Vector2f position(150.0f, 100.0f);
            sf::Vector2f size(50.0f, 50.0f);
            sf::Color color(sf::Color::Blue);
            sf::RectangleShape rectangle(size);
            rectangle.setPosition(position);
            rectangle.setFillColor(color);
            buffer2.draw(rectangle);
        }

        if (usingBuffer1) {
            buffer1.display();
            sf::Sprite sprite(buffer1.getTexture());
            window.draw(sprite);
        } else {
            buffer2.display();
            sf::Sprite sprite(buffer2.getTexture());
            window.draw(sprite);
        }
        display();

        usingBuffer1 = !usingBuffer1;
            
    }

}