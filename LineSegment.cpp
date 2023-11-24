#include "LineSegment.h"

#include "Point2D.h"

LineSegment::LineSegment(Point2D& start, Point2D& end) : startPoint(start), endPoint(end) {}

Point2D& LineSegment::getStart()  {
    return startPoint;
}

Point2D& LineSegment::getEnd()  {
    return endPoint;
}

void LineSegment::setStart( Point2D& newStart) {
    startPoint = newStart;
}

void LineSegment::setEnd( Point2D& newEnd) {
    endPoint = newEnd;
}

void LineSegment::draw(PrimitiveRenderer& renderer, sf::Color color, bool incrementalAlgorithm) {
    sf::Vector2f startCoords = startPoint.getCoordinates();
    sf::Vector2f endCoords = endPoint.getCoordinates();

    if (incrementalAlgorithm) {
        renderer.drawLineInstrukcja(startCoords, endCoords, color);
            
    }
    else {
        renderer.drawLine(startCoords, endCoords, color);
      
    }
}
void LineSegment::translate(float dx, float dy) {
    startPoint.translate(dx, dy);
    endPoint.translate(dx, dy);
}

void LineSegment::rotate(float angle) {
    startPoint.rotate(angle);
    endPoint.rotate(angle);
}

void LineSegment::scale(float factor) {
    startPoint.scale(factor);
    endPoint.scale(factor);
}

void LineSegment::drawCherry(PrimitiveRenderer& renderer, sf::Vector2f position) {
    
    sf::Vector2f point(position.x + 15.0f, position.y+15.0f);
    renderer.drawCircleInstrukcja(point, 15.0f, sf::Color(139, 0, 34)); 
   

   
    sf::Vector2f stemStart(position.x + 15.0f, position.y - 15.0f);
    sf::Vector2f stemEnd(position.x + 15.0f, position.y - 25.0f);
    renderer.drawLine(stemStart, stemEnd, sf::Color(34, 139, 34)); 

   
    sf::Vector2f leaf1(position.x + 7.5f, position.y - 15.0f);
    sf::Vector2f leaf2(position.x + 22.5f, position.y - 15.0f);
    sf::Vector2f leaf3(position.x + 10.0f, position.y - 20.0f);
    sf::Vector2f leaf4(position.x + 20.0f, position.y - 20.0f);

    sf::Vector2f point2(position.x + 15.0f, position.y );
    renderer.drawLine(point2, leaf1, sf::Color(34, 139, 34)); 
    renderer.drawLine(point2, leaf2, sf::Color(34, 139, 34)); 

    renderer.drawLine(point2, leaf3, sf::Color(34, 139, 34)); 
    renderer.drawLine(point2, leaf4, sf::Color(34, 139, 34)); 

    renderer.drawLine(point2, leaf3, sf::Color(0, 128, 0, 100)); 
    renderer.drawLine(point2, leaf4, sf::Color(0, 128, 0, 100)); 
    sf::Vector2f point3(position.x + 15.0f, position.y+2.0f);
   
    renderer.boundryFill(point3, sf::Color(255, 0, 0), sf::Color(139, 0, 34)); 
}