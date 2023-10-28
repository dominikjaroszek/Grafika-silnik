#include "Point2D.h"

Point2D::Point2D(float xx, float yy) 
{
    x = xx;
    y = yy;
}

sf::Vector2f Point2D::getCoordinates() {
    return sf::Vector2f(x, y);
}

float Point2D::getCoordinatesY()
{
    return y;
}
float Point2D::getCoordinatesX()
{
    return x;
}

void Point2D::setCoordinates(float newX, float newY) {
    x = newX;
    y = newY;
}

void Point2D::draw(PrimitiveRenderer &renderer,sf::Color color) {
    renderer.drawRectangle(getCoordinates(), sf::Vector2f(1.0f, 1.0f), color);
}

void Point2D::translate(float dx, float dy)  {
    x += dx;
    y += dy;
}

void Point2D::rotate(float angle) {
    float currentX = x;
    float currentY = y;
    x = currentX * cos(angle) - currentY * sin(angle);
    y = currentX * sin(angle) + currentY * cos(angle);
}

void Point2D::scale(float factor)  {
    x *= factor;
    y *= factor;
}