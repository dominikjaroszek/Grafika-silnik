#pragma once

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"

class LineSegment {
public:
    LineSegment( Point2D start, Point2D end);

    Point2D getStart() ;
    Point2D getEnd() ;
    void setStart( Point2D newStart);
    void setEnd( Point2D newEnd);

    void draw(PrimitiveRenderer renderer, sf::Color color , bool incrementalAlgorithm );

private:
    Point2D startPoint;
    Point2D endPoint;

};
