#include "LineSegment.h"

LineSegment::LineSegment(Point2D start,  Point2D end)
{
    startPoint = start;
    endPoint = end;
}

Point2D LineSegment::getStart()  {
    return startPoint;
}

Point2D LineSegment::getEnd()  {
    return endPoint;
}

void LineSegment::setStart( Point2D newStart) {
    startPoint = newStart;
}

void LineSegment::setEnd( Point2D newEnd) {
    endPoint = newEnd;
}

void LineSegment::draw(PrimitiveRenderer renderer, sf::Color& color, bool incrementalAlgorithm) {
    sf::Vector2f startCoords = startPoint.getCoordinates();
    sf::Vector2f endCoords = endPoint.getCoordinates();

    if (incrementalAlgorithm) {
        renderer.drawLineInstrukcja(startCoords, endCoords, color);
        
    }
    else {
        renderer.drawLine(startCoords, endCoords, color);
      
    }
}
