#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "PrimitiveRenderer.h"
#include "Engine.h"

int main() {
    Engine& gameEngine = Engine::getInstance();
    gameEngine.init(800, 600, "Game Window");
    //gameEngine.init2b(800, 600, "Game Window");
   // gameEngine.setFramesPerSecond(30);
    gameEngine.run();
    //gameEngine.run2b();
    

    return 0;
}