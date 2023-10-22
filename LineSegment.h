#pragma once

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"

class LineSegment {
public:
    LineSegment(const Point2D& start, const Point2D& end);

    Point2D getStart() const;
    Point2D getEnd() const;
    void setStart( Point2D newStart);
    void setEnd(const Point2D& newEnd);

    void draw(PrimitiveRenderer& renderer, const sf::Color& color , bool incrementalAlgorithm );

private:
    Point2D startPoint;
    Point2D endPoint;
};
