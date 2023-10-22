#include "LineSegment.h"

LineSegment::LineSegment(const Point2D& start, const Point2D& end) : startPoint(start), endPoint(end) {}

Point2D LineSegment::getStart() const {
    return startPoint;
}

Point2D LineSegment::getEnd() const {
    return endPoint;
}

void LineSegment::setStart( Point2D newStart) {
    startPoint = newStart;
}

void LineSegment::setEnd(const Point2D& newEnd) {
    endPoint = newEnd;
}

void LineSegment::draw(PrimitiveRenderer& renderer, const sf::Color& color, bool incrementalAlgorithm) {
    sf::Vector2f startCoords = startPoint.getCoordinates();
    sf::Vector2f endCoords = endPoint.getCoordinates();

    if (incrementalAlgorithm) {
        // Tutaj mo¿esz zaimplementowaæ rysowanie odcinka przy u¿yciu algorytmu przyrostowego
        // z wykorzystaniem metod z Point2D
        // ...

        // Przyk³ad z u¿yciem domyœlnego algorytmu (wykorzystuj¹c sf::VertexArray)
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = startCoords;
        line[1].position = endCoords;
        line[0].color = color;
        line[1].color = color;
        
    }
    else {
        // Domyœlny algorytm rysowania odcinka
        sf::VertexArray line(sf::LinesStrip, 2);
        line[0].position = startCoords;
        line[1].position = endCoords;
        line[0].color = color;
        line[1].color = color;
      
    }
}
