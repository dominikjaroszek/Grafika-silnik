#include "Point2D.h"

Point2D::Point2D(float xx, float yy) 
{
    x = xx;
    y = yy;
}

sf::Vector2f Point2D::getCoordinates() {
    return sf::Vector2f(x, y);
}

void Point2D::setCoordinates(float newX, float newY) {
    x = newX;
    y = newY;
}

void Point2D::draw(PrimitiveRenderer renderer,sf::Color color) {
    renderer.drawRectangle(getCoordinates(), sf::Vector2f(1.0f, 1.0f), color);
}