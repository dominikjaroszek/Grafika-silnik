#include "PrimitiveRenderer.h"
#include <iostream>
#include<vector>
#include <cmath>
#include <stack>
#include <set>



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

void PrimitiveRenderer::brokeLine(std::vector<Point2D> coordinates, sf::Color color, bool closed)
{
    int i;
    for (i = 1; i < coordinates.size(); i++) {
        drawLineInstrukcja(coordinates[i-1].getCoordinates(), coordinates[i].getCoordinates(), color);
    }

    if (closed) {
        drawLineInstrukcja(coordinates[0].getCoordinates(), coordinates[i-1].getCoordinates(), color);
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
    const int windowWidth = 800;
    const int windowHeight = 600;

    if (point.x < 0 || point.x >= windowWidth || point.y < 0 || point.y >= windowHeight)
        return;

    sf::Texture texture;
    texture.create(windowWidth, windowHeight);
    texture.update(window);
    sf::Image screen = texture.copyToImage();

    std::stack<sf::Vector2i> DSD;
    DSD.push({ static_cast<int>(point.x), static_cast<int>(point.y) });

    while (!DSD.empty()) {
        sf::Vector2i P = DSD.top();
        DSD.pop();

        if (P.x < 0 || P.x >= windowWidth || P.y < 0 || P.y >= windowHeight)
            continue;

        sf::Color pixelColor = screen.getPixel(P.x, P.y);

        if (pixelColor == fillColor || pixelColor == borderColor)
            continue;

        this->drawPoint(sf::Vector2f(P.x, P.y), fillColor);
        screen.setPixel(P.x, P.y, fillColor);

        // E
        DSD.push({ P.x + 1, P.y });

        // W
        DSD.push({ P.x - 1, P.y });

        // N
        DSD.push({ P.x, P.y + 1 });

        // S
        DSD.push({ P.x, P.y - 1 });
    }

}

void PrimitiveRenderer::floodFill(sf::Vector2f point, sf::Color fillColor) {
    const int windowWidth = 800;
    const int windowHeight = 600;

    if (point.x < 0 || point.x >= windowWidth || point.y < 0 || point.y >= windowHeight)
        return;

    sf::Texture texture;
    texture.create(windowWidth, windowHeight);
    texture.update(window);
    sf::Image screen = texture.copyToImage();

    std::stack<sf::Vector2i> DSD;
    DSD.push({ static_cast<int>(point.x), static_cast<int>(point.y) });
    sf::Color backgroundColor = screen.getPixel(point.x, point.y);

    while (!DSD.empty()) {
        sf::Vector2i P = DSD.top();
        DSD.pop();

        if (P.x < 0 || P.x >= windowWidth || P.y < 0 || P.y >= windowHeight)
            continue;

        sf::Color pixelColor = screen.getPixel(P.x, P.y);

        if (pixelColor == fillColor || pixelColor != backgroundColor)
            continue;

        this->drawPoint(sf::Vector2f(P.x, P.y), fillColor);
        screen.setPixel(P.x, P.y, fillColor);

        // E
        DSD.push({ P.x + 1, P.y });

        // W
        DSD.push({ P.x - 1, P.y });

        // N
        DSD.push({ P.x, P.y + 1 });

        // S
        DSD.push({ P.x, P.y - 1 });
    }

}


bool PrimitiveRenderer::segmentsIntersect(LineSegment &A, LineSegment &B) {
    
    float x1 = A.getStart().getCoordinatesX(), y1 = A.getStart().getCoordinatesY();
    float x2 = A.getEnd().getCoordinatesX(), y2 = A.getEnd().getCoordinatesY();
    float x3 = B.getStart().getCoordinatesX(), y3 = B.getStart().getCoordinatesY();
    float x4 = B.getEnd().getCoordinatesX(), y4 = B.getEnd().getCoordinatesY();

    
    float s1 = x1 * (y3 - y4) + (y1 * (x4 - x3)) + ((x3 * y4) - (y3 * x4));
    float s2 = (x2 * (y3 - y4)) + (y2 * (x4 - x3)) + ((x3 * y4) - (y3 * x4));
    float s3 = (x3 * (y1 - y2)) + (y3 * (x2 - x1)) + ((x1 * y2) - (y1 * x2));
    float s4 = (x4 * (y1 - y2)) + (y4 * (x2 - x1)) + ((x1 * y2) - (y1 * x2));


    
    if (s1 < 0.00 && s2>0.00 && s3 > 0.00 && s4 < 0.00 || s1 > 0.00 && s2 < 0.00 && s3 < 0.00 && s4 > 0.00) {
        
        return 1;
    }
    else {
        // Odcinki nie przecinaj¹ siê
        return 0;
    }

    return 0;
}




void PrimitiveRenderer::drawPolygon(std::vector<LineSegment>& lines, sf::Color color) {

    for (int i = 1; i < lines.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (segmentsIntersect(lines[i], lines[j])) {
                return;
                
            }
        }
    }
    /*if (segmentsintersect(points[points.size() - 1], points[0], points[1], points[points.size() - 1])) {
        return;*/
    


    // Narysuj wielok¹t
    
    for (int i = 0; i < lines.size(); i++) {
        drawLine(lines[i].getStart().getCoordinates(), lines[i].getEnd().getCoordinates(), color);
    }
    
}

void PrimitiveRenderer::drawCherry(sf::Vector2f position) {

    sf::Vector2f point(position.x + 15.0f, position.y + 15.0f);
    this->drawCircleInstrukcja(point, 15.0f, sf::Color(139, 0, 34));



    sf::Vector2f stemStart(position.x + 15.0f, position.y - 15.0f);
    sf::Vector2f stemEnd(position.x + 15.0f, position.y - 25.0f);
    this->drawLine(stemStart, stemEnd, sf::Color(34, 139, 34));


    sf::Vector2f leaf1(position.x + 7.5f, position.y - 15.0f);
    sf::Vector2f leaf2(position.x + 22.5f, position.y - 15.0f);
    sf::Vector2f leaf3(position.x + 10.0f, position.y - 20.0f);
    sf::Vector2f leaf4(position.x + 20.0f, position.y - 20.0f);

    sf::Vector2f point2(position.x + 15.0f, position.y);
    this->drawLine(point2, leaf1, sf::Color(34, 139, 34));
    this->drawLine(point2, leaf2, sf::Color(34, 139, 34));

    this->drawLine(point2, leaf3, sf::Color(34, 139, 34));
    this->drawLine(point2, leaf4, sf::Color(34, 139, 34));

    this->drawLine(point2, leaf3, sf::Color(0, 128, 0, 100));
    this->drawLine(point2, leaf4, sf::Color(0, 128, 0, 100));
    sf::Vector2f point3(position.x + 15.0f, position.y + 2.0f);

    this->boundryFill(point3, sf::Color(255, 0, 0), sf::Color(139, 0, 34));
}

void PrimitiveRenderer::drawTree(sf::Vector2f position) {

   
    this->drawRectangle(position, sf::Vector2f(50.f, 200.f), sf::Color(139, 89, 39));
    sf::Vector2f tmp(position.x, position.y);
    Point2D p1(tmp.x, tmp.y);
    tmp.x += -100;
    tmp.y += +30;
    Point2D p2(tmp.x, tmp.y);

    tmp.x += +50;
    tmp.y += -50;
    Point2D p3(tmp.x, tmp.y);

    tmp.x += -40;
    tmp.y += -20;
    Point2D p4(tmp.x, tmp.y);

    tmp.x += +30;
    tmp.y += -30;
    Point2D p5(tmp.x, tmp.y);

    tmp.x += -20;
    tmp.y +=  0;
    Point2D p6(tmp.x, tmp.y);

    Point2D p7(position.x + 25, tmp.y-50);

   
    std::vector<Point2D> coordinatesLeft;
    coordinatesLeft.push_back(p1);
    coordinatesLeft.push_back(p2);
    coordinatesLeft.push_back(p3);
    coordinatesLeft.push_back(p4);
    coordinatesLeft.push_back(p5);
    coordinatesLeft.push_back(p6);
    coordinatesLeft.push_back(p7);

 
    this->brokeLine(coordinatesLeft, sf::Color(10, 250, 10), 0);





    tmp.x = position.x + 50;
    tmp.y = position.y;
    Point2D p11(tmp.x, tmp.y);
    tmp.x += +100;
    tmp.y += +30;
    Point2D p22(tmp.x, tmp.y);

    tmp.x += -50;
    tmp.y += -50;
    Point2D p33(tmp.x, tmp.y);

    tmp.x += +40;
    tmp.y += -20;
    Point2D p44(tmp.x, tmp.y);

    tmp.x += -30;
    tmp.y += -30;
    Point2D p55(tmp.x, tmp.y);

    tmp.x += +20;
    tmp.y += 0;
    Point2D p66(tmp.x, tmp.y);

    Point2D p77(position.x + 25, tmp.y - 50);

    std::vector<Point2D> coordinatesRight;
    coordinatesRight.push_back(p11);
    coordinatesRight.push_back(p22);
    coordinatesRight.push_back(p33);
    coordinatesRight.push_back(p44);
    coordinatesRight.push_back(p55);
    coordinatesRight.push_back(p66);
    coordinatesRight.push_back(p77);


    this->brokeLine(coordinatesRight, sf::Color(10, 250, 10), 0);


   
}

