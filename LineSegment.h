#pragma once

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "TransformableObject.h"

class PrimitiveRenderer; 
class Point2D; 

/// Odpowiada za metody zwi�zane z rysowaniem linii
/// 
/// Klasa dziedziczy po TransformableObject 
/// 

class LineSegment :public TransformableObject {
public:
    LineSegment(Point2D& start, Point2D& end);

    /// Metoda zwracaj�ca pocz�tek linii
    ///
    /// @returns  obiekt klasy Point2D
    Point2D& getStart();  
    /// Metoda zwracaj�ca koniec linii
    ///
    /// @returns  obiekt klasy Point2D
    Point2D& getEnd(); 
    /// Metoda ustawiaj�ca pocz�tek linii
    ///
    /// @param newStart Przyjmuje obiekt klasy Point2D �eby ustawi� pocz�tek
    void setStart(Point2D& newStart);
    /// Metoda ustawiaj�ca koniec linii
    ///
    /// @param newStart Przyjmuje obiekt klasy Point2D �eby ustawi� koniec
    void setEnd(Point2D& newEnd);
    /// Metoda rysuj�ca linie
    ///
    /// W metodzie wybieramy spos�b rysowania linii. Za pomoc� naszego algorytmu lub za pomoc� funkcji wbudowanych
    /// @param renderer Przyjmuje obiekt klasy PrimitiveRenderer do rysowania linii
    /// @param color Kolor linii
    /// @param incrementalAlgorithm Typ bool do wyboru jak chcemy rysowa� lini�, True - nasz algorytm, False - funkcja wbudowana
    void draw(PrimitiveRenderer& renderer, sf::Color color, bool incrementalAlgorithm);
    /// Metoda przesuwa obiekt w p�aszczy�nie dwuwymiarowej 
    ///
    /// @param dx Przesuni�cie wzd�u� osi X.
    /// @param dy Przesuni�cie wzd�u� osi Y.
    void translate(float dx, float dy) override;
    /// Obraca obiekt o okre�lony k�t. 
    ///
    /// @param angle K�t obrotu w stopniach.
    void rotate(float angle) override;
    /// Skaluje obiekt o okre�lony wsp�czynnik. 
    ///
    /// @param factor Wsp�czynnik skalowania.
    void scale(float factor) override;
    void drawCherry(PrimitiveRenderer& renderer, sf::Vector2f position);

private:
    /// Referencja do punktu pocz�tkowego obiektu. 
    ///
    /// Sk�adowa startPoint przechowuje referencj� do obiektu klasy Point2D, kt�ry reprezentuje punkt pocz�tkowy obiektu.
    
    Point2D& startPoint; 
    /// Referencja do punktu ko�cowego obiektu. 
    ///
    /// Sk�adowa endPoint przechowuje referencj� do obiektu klasy Point2D, kt�ry reprezentuje punkt ko�cowy obiektu.
    Point2D& endPoint;
};
