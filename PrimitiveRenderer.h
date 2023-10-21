#include <SFML/Graphics.hpp>

#pragma once

class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window) : window(window) {}

    void drawRectangle(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color) {
        sf::RectangleShape rectangle(size);
        rectangle.setPosition(position);
        rectangle.setFillColor(color);
        window.draw(rectangle);
    }

    void drawCircle(const sf::Vector2f& position, float radius, const sf::Color& color) {
        sf::CircleShape circle(radius);
        circle.setPosition(position);
        circle.setFillColor(color);
        window.draw(circle);
    }

    void drawLine(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Color& color) {
        sf::Vertex line[] = {
            sf::Vertex(point1, color),
            sf::Vertex(point2, color)
        };
        window.draw(line, 2, sf::Lines);
    }

private:
    sf::RenderWindow& window;
};

