#pragma once

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "TransformableObject.h"

class PrimitiveRenderer; 
class Point2D; 

/// Odpowiada za metody zwi¹zane z rysowaniem linii
/// 
/// Klasa dziedziczy po TransformableObject 
/// 

class LineSegment :public TransformableObject {
public:
    LineSegment(Point2D& start, Point2D& end);

    /// Metoda zwracaj¹ca pocz¹tek linii
    ///
    /// @returns  obiekt klasy Point2D
    Point2D& getStart();  
    /// Metoda zwracaj¹ca koniec linii
    ///
    /// @returns  obiekt klasy Point2D
    Point2D& getEnd(); 
    /// Metoda ustawiaj¹ca pocz¹tek linii
    ///
    /// @param newStart Przyjmuje obiekt klasy Point2D ¿eby ustawiæ pocz¹tek
    void setStart(Point2D& newStart);
    /// Metoda ustawiaj¹ca koniec linii
    ///
    /// @param newStart Przyjmuje obiekt klasy Point2D ¿eby ustawiæ koniec
    void setEnd(Point2D& newEnd);
    /// Metoda rysuj¹ca linie
    ///
    /// W metodzie wybieramy sposób rysowania linii. Za pomoc¹ naszego algorytmu lub za pomoc¹ funkcji wbudowanych
    /// @param renderer Przyjmuje obiekt klasy PrimitiveRenderer do rysowania linii
    /// @param color Kolor linii
    /// @param incrementalAlgorithm Typ bool do wyboru jak chcemy rysowaæ liniê, True - nasz algorytm, False - funkcja wbudowana
    void draw(PrimitiveRenderer& renderer, sf::Color color, bool incrementalAlgorithm);
    /// Metoda przesuwa obiekt w p³aszczyŸnie dwuwymiarowej 
    ///
    /// @param dx Przesuniêcie wzd³u¿ osi X.
    /// @param dy Przesuniêcie wzd³u¿ osi Y.
    void translate(float dx, float dy) override;
    /// Obraca obiekt o okreœlony k¹t. 
    ///
    /// @param angle K¹t obrotu w stopniach.
    void rotate(float angle) override;
    /// Skaluje obiekt o okreœlony wspó³czynnik. 
    ///
    /// @param factor Wspó³czynnik skalowania.
    void scale(float factor) override;
    void drawCherry(PrimitiveRenderer& renderer, sf::Vector2f position);

private:
    /// Referencja do punktu pocz¹tkowego obiektu. 
    ///
    /// Sk³adowa startPoint przechowuje referencjê do obiektu klasy Point2D, który reprezentuje punkt pocz¹tkowy obiektu.
    
    Point2D& startPoint; 
    /// Referencja do punktu koñcowego obiektu. 
    ///
    /// Sk³adowa endPoint przechowuje referencjê do obiektu klasy Point2D, który reprezentuje punkt koñcowy obiektu.
    Point2D& endPoint;
};
