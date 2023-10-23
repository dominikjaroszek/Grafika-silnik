#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Point2D;

class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window);
    void drawRectangle( sf::Vector2f position,   sf::Vector2f size,   sf::Color color);
    void drawCircle( sf::Vector2f position, float radius,   sf::Color color);
    void drawLine( sf::Vector2f point1,  sf::Vector2f point2,   sf::Color color);
    void drawLineInstrukcja(  sf::Vector2f point1,   sf::Vector2f point2,   sf::Color color);
    void brokeLine(std::vector<sf::Vector2f> points, sf::Color color, bool closed);
    void drawPoint(sf::Vector2f point, sf::Color color);
    void drawCircleInstrukcja(sf::Vector2f point,float R, sf::Color color);
    void drawElipseInstrukcja();
    

private:
    sf::RenderWindow& window;
};