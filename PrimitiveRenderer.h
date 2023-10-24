#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "LineSegment.h"
#include "Point2D.h"

class LineSegment;

class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window);
    void drawRectangle( sf::Vector2f position,   sf::Vector2f size,   sf::Color color);
    void drawCircle( sf::Vector2f position, float radius,   sf::Color color);
    void drawLine( sf::Vector2f point1,  sf::Vector2f point2,   sf::Color color);
    void drawLineInstrukcja(  sf::Vector2f point1,   sf::Vector2f point2,   sf::Color color);
    void brokeLine(std::vector<Point2D> points, sf::Color color, bool closed);
    void drawCircleInstrukcja(sf::Vector2f point, sf::Color color);
    bool segmentsIntersect(LineSegment& A, LineSegment &B);
    void drawPolygon(std::vector<LineSegment>& lines, sf::Color color);
private:
    sf::RenderWindow& window;
};