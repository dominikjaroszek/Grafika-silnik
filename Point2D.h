#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "TransformableObject.h"
class PrimitiveRenderer;

class Point2D :public TransformableObject {
public:
    Point2D(float x = 0.0f, float y = 0.0f);
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;
    sf::Vector2f getCoordinates() ;
    void setCoordinates(float newX, float newY);
    void draw(PrimitiveRenderer &renderer, sf::Color color );
    float getCoordinatesY();
    float getCoordinatesX();

private:
    float x;
    float y;
};

