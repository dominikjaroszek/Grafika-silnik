#include <SFML/Graphics.hpp>
#pragma once

class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow& window) : window(window) {}

    void drawRectangle(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color);

    void drawCircle(const sf::Vector2f& position, float radius, const sf::Color& color);

    void drawLine(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Color& color);

private:
    sf::RenderWindow& window;
};

