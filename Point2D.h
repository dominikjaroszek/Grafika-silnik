#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"

class Point2D {
public:
    Point2D(float x = 0.0f, float y = 0.0f);

    sf::Vector2f getCoordinates() ;
    void setCoordinates(float newX, float newY);
    void draw(PrimitiveRenderer renderer, sf::Color color );

private:
    float x;
    float y;
};

