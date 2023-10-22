#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "PrimitiveRenderer.h"
#include "Engine.h"

int main() {
    Engine& gameEngine = Engine::getInstance();
    gameEngine.init(800, 600, "Game Window");
   
    gameEngine.run();
    

    return 0;
}