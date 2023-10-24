#pragma once

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"

class PrimitiveRenderer; // Deklaracja wstêpna klasy PrimitiveRenderer
class Point2D; // Deklaracja wstêpna klasy Point2D

class LineSegment {
public:
    LineSegment(Point2D& start, Point2D& end);

    Point2D& getStart();  // Zwracaj referencje do Point2D
    Point2D& getEnd();  // Zwracaj referencje do Point2D
    void setStart(Point2D& newStart);
    void setEnd(Point2D& newEnd);

    void draw(PrimitiveRenderer& renderer, sf::Color color, bool incrementalAlgorithm);

private:
    Point2D& startPoint; // Zamiast referencji, u¿yj obiektów Point2D
    Point2D& endPoint;
};
