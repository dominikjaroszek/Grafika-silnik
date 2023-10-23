#include "PrimitiveRenderer.h"
#include <iostream>
#include<vector>
#include <cmath>
#include <stack>

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow& window) : window(window) {
    // Konstruktor - implementacja, jeœli jest potrzebna
}

void PrimitiveRenderer::drawRectangle(  sf::Vector2f position,   sf::Vector2f size,   sf::Color color) {
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

void PrimitiveRenderer::drawCircle(  sf::Vector2f position, float radius,   sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setPosition(position);
    circle.setFillColor(color);
    window.draw(circle);
}

void PrimitiveRenderer::drawLine(  sf::Vector2f point1,   sf::Vector2f point2,   sf::Color color) {
    sf::Vertex line[] = {
        sf::Vertex(point1, color),
        sf::Vertex(point2, color)
    };
    window.draw(line, 2, sf::Lines);
}

void PrimitiveRenderer::drawPoint(sf::Vector2f point, sf::Color color) {
    sf::Vector2f step = sf::Vector2f(1, 1);
    sf::RectangleShape pixel(step);
    pixel.setPosition(point);
    pixel.setFillColor(color);
    window.draw(pixel);
}



void PrimitiveRenderer::drawLineInstrukcja(  sf::Vector2f startingPoint,   sf::Vector2f endPoint,   sf::Color color) {
    float delta_x = std::abs(endPoint.x - startingPoint.x);
    float delta_y = std::abs(endPoint.y - startingPoint.y);
    sf::Vector2f currentPoint = startingPoint;
    float m = 0;

    if (delta_x > delta_y) {
        m = delta_y / delta_x;
        for (int i = 0; i <= delta_x; i++) {
            float temp = currentPoint.y;
            currentPoint.y = (int)currentPoint.y;
            this->drawPoint(currentPoint, color);
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
            this->drawPoint(currentPoint, color);
   
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

void PrimitiveRenderer::brokeLine(std::vector<sf::Vector2f> points, sf::Color color, bool closed)
{
    int i;
    for (i = 1; i < points.size(); i++) {
        drawLineInstrukcja(points[i-1], points[i], color);
    }

    if (closed) {
        drawLineInstrukcja(points[0], points[i-1], color);
    }

}

void PrimitiveRenderer::drawCircleInstrukcja(sf::Vector2f point,float R, sf::Color color) {
    
    sf::Vector2f currentPoint;
   
    float step = 1.0 / R;

    for (float a = 0; a < 1.5708; a += step) {

        currentPoint.x = point.x + R * cos(a) + 0.5;
        currentPoint.y = point.y - R * sin(a) + 0.5;
        this->drawPoint(currentPoint, color);

        currentPoint.x = point.x + R * cos(a) + 0.5;
        currentPoint.y = point.y + R * sin(a) + 0.5;
        this->drawPoint(currentPoint, color);

        currentPoint.x = point.x - R * cos(a) + 0.5;
        currentPoint.y = point.y + R * sin(a) + 0.5;
        this->drawPoint(currentPoint, color);

        currentPoint.x = point.x - R * cos(a) + 0.5;
        currentPoint.y = point.y - R * sin(a) + 0.5;
        this->drawPoint(currentPoint, color);
    }



}

void PrimitiveRenderer::drawElipseInstrukcja(sf::Vector2f point, float Rx, float Ry, sf::Color color) {
    sf::Vector2f currentPoint;

    float step = -1;
    if (Rx > Ry)
        step = 1.0 / Rx;
    else
        step = 1.0 / Ry;

    for (float a = 0; a < 1.5708; a += step) {

        currentPoint.x = point.x + Rx * cos(a) + 0.5;
        currentPoint.y = point.y - Ry * sin(a) + 0.5;
        this->drawPoint(currentPoint, color);

        currentPoint.x = point.x + Rx * cos(a) + 0.5;
        currentPoint.y = point.y + Ry * sin(a) + 0.5;
        this->drawPoint(currentPoint, color);

        currentPoint.x = point.x - Rx * cos(a) + 0.5;
        currentPoint.y = point.y + Ry * sin(a) + 0.5;
        this->drawPoint(currentPoint, color);

        currentPoint.x = point.x - Rx * cos(a) + 0.5;
        currentPoint.y = point.y - Ry * sin(a) + 0.5;
        this->drawPoint(currentPoint, color);
    }
}


void PrimitiveRenderer::boundryFill(sf::Vector2f point, sf::Color fillColor, sf::Color borderColor) {
    std::stack<sf::Vector2f> DSD;
    //sf::Color pixelColor;
    DSD.push(point);


    while (!DSD.empty()) {
        sf::Vector2f P = DSD.top();
        DSD.pop();

        sf::Vector2u windowSize = window.getSize();
        sf::Texture texture;
        texture.create(windowSize.x, windowSize.y);
        texture.update(window);
        sf::Image screenshot = texture.copyToImage();
        sf::Color pixelColor = screenshot.getPixel(P.x, P.y);

        if (pixelColor == fillColor || pixelColor == borderColor)
            continue;

        this->drawPoint(P, fillColor);
        
        
        // E
        P.x += 1;
        DSD.push(P);
        
        // W
        P.x -= 2;
        DSD.push(P);
        
        // N
        P.x += 1;
        P.y += 1;
        DSD.push(P);

        // S
        P.y -= 2;
        DSD.push(P);

        



    }
}