#include "PrimitiveRenderer.h"
#include <iostream>

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window) : window(window) {
    // Konstruktor - implementacja, jeœli jest potrzebna
}

void PrimitiveRenderer::drawRectangle(const sf::Vector2f position, const sf::Vector2f size, const sf::Color color) {
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

void PrimitiveRenderer::drawCircle(const sf::Vector2f position, float radius, const sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setPosition(position);
    circle.setFillColor(color);
    window.draw(circle);
}

void PrimitiveRenderer::drawLine(const sf::Vector2f point1, const sf::Vector2f point2, const sf::Color color) {
    sf::Vertex line[] = {
        sf::Vertex(point1, color),
        sf::Vertex(point2, color)
    };
    window.draw(line, 2, sf::Lines);
}

void PrimitiveRenderer::drawLineIncremental(const sf::Vector2f point1, const sf::Vector2f point2, const sf::Color color) {
    // Algorytm przyrostowy do rysowania odcinka
    sf::Vector2f delta = point2 - point1;
    sf::Vector2f step = sf::Vector2f(1, 1);

    if (delta.x < 0) {
        step.x = -1;
    }
    if (delta.y < 0) {
        step.y = -1;
    }

    delta.x = std::abs(delta.x);
    delta.y = std::abs(delta.y);

    float error = delta.x - delta.y;
    sf::Vector2f currentPoint = point1;

    while (currentPoint != point2) {
        // Rysuj punkt na obecnym miejscu
        sf::RectangleShape pixel(step);
        pixel.setPosition(currentPoint);
        pixel.setFillColor(color);
        window.draw(pixel);

        float error2 = 2 * error;

        if (error2 > -delta.y) {
            error -= delta.y;
            currentPoint.x += step.x;
        }
        if (error2 < delta.x) {
            error += delta.x;
            currentPoint.y += step.y;
        }
    }
}


void PrimitiveRenderer::drawLineInstrukcja(const sf::Vector2f startingPoint, const sf::Vector2f endPoint, const sf::Color color) {
    float delta_x = std::abs(endPoint.x - startingPoint.x);
    float delta_y = std::abs(endPoint.y - startingPoint.y);
    sf::Vector2f currentPoint = startingPoint;
    sf::Vector2f step = sf::Vector2f(1, 1);
    sf::RectangleShape pixel(step);
    float m = 0;

    if (delta_x > delta_y) {
        m = delta_y / delta_x;
        for (int i = 0; i <= delta_x; i++) {
            float temp = currentPoint.y;
            currentPoint.y = (int)currentPoint.y;
            pixel.setPosition(currentPoint);
            pixel.setFillColor(color);
            window.draw(pixel);
            currentPoint.y = temp;

            if (startingPoint.x < endPoint.x)
                currentPoint.x += 1;
            else
                currentPoint.x -= 1;

            if (startingPoint.y < endPoint.y)
                currentPoint.y += m;
            else
                currentPoint.y -= m;
        }
    }
    else {
        m = delta_x / delta_y;
        for (int i = 0; i <= delta_y; i++) {
            float temp = currentPoint.x;
            currentPoint.x = (int)currentPoint.x;
            pixel.setPosition(currentPoint);
            pixel.setFillColor(color);
            window.draw(pixel);
            currentPoint.x = temp;

            if (startingPoint.x < endPoint.x)
                currentPoint.x += m;
            else
                currentPoint.x -= m;

            if (startingPoint.y < endPoint.y)
                currentPoint.y += 1;
            else
                currentPoint.y -= 1;
        }
    }

    


    
}