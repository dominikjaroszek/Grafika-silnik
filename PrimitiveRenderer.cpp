#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window) : window(window) {
    // Konstruktor - implementacja, jeœli jest potrzebna
}

void PrimitiveRenderer::drawRectangle(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color) {
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

void PrimitiveRenderer::drawCircle(const sf::Vector2f& position, float radius, const sf::Color& color) {
    sf::CircleShape circle(radius);
    circle.setPosition(position);
    circle.setFillColor(color);
    window.draw(circle);
}

void PrimitiveRenderer::drawLine(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Color& color) {
    sf::Vertex line[] = {
        sf::Vertex(point1, color),
        sf::Vertex(point2, color)
    };
    window.draw(line, 2, sf::Lines);
}

void PrimitiveRenderer::drawLineIncremental(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Color& color) {
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