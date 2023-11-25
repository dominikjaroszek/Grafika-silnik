#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "TransformableObject.h"
class PrimitiveRenderer;

/// Klasa reprezentuj�ca punkt w dwuwymiarowej przestrzeni.
/// 
/// Klasa Point2D dziedziczy po klasie TransformableObject, co oznacza,�e mo�e by� transformowana za pomoc� translacji, rotacji i skalowania.


class Point2D :public TransformableObject {
public:
    /// Konstruktor klasy Point2D.
    ///
    /// @param x Warto�� wsp�rz�dnej x punktu (domy�lnie 0.0f).
    /// @param y Warto�� wsp�rz�dnej y punktu(domy�lnie 0.0f).
    Point2D(float x = 0.0f, float y = 0.0f);
    /// Metoda przesuwaj�ca punkt o okre�lone warto�ci.
    /// 
    /// @param dx Przesuni�cie wzd�u� osi X.
    /// @param dy Przesuni�cie wzd�u� osi Y.
    void translate(float dx, float dy) override;
    /// Metoda obracaj�ca punkt o zadany k�t.
    /// 
    /// @param angle K�t obrotu w stopniach.
    void rotate(float angle) override;
    /// Metoda obracaj�ca punkt o zadany k�t.
    /// 
    /// @param angle K�t obrotu w stopniach.
    void scale(float factor) override;
    /// Pobiera wsp�rz�dne punktu jako obiekt sf::Vector2f.
    /// 
    /// @return Wsp�rz�dne punktu jako obiekt sf::Vector2f.
    sf::Vector2f getCoordinates() ;
    /// Ustawia nowe wsp�rz�dne punktu.
    /// 
    /// @param newX Nowa warto�� wsp�rz�dnej x.
    /// @param newY Nowa warto�� wsp�rz�dnej y.
    void setCoordinates(float newX, float newY);
    /// Rysuje punkt przy u�yciu danego PrimitiveRenderer.
    /// 
    /// @param renderer Obiekt do rysowania.
    /// @param color Kolor, kt�ry ma by� u�yty do rysowania punktu.
    void draw(PrimitiveRenderer &renderer, sf::Color color );
    /// Pobiera warto�� wsp�rz�dnej y punktu.
    /// 
    /// @return Warto�� wsp�rz�dnej y punktu.
    float getCoordinatesY();
    /// Pobiera warto�� wsp�rz�dnej x punktu.
    /// 
    /// @return Warto�� wsp�rz�dnej x punktu.
    float getCoordinatesX();

private:
    /// Wsp�rz�dna x punktu
    
    float x;
    /// Wsp�rz�dna y punktu
    float y;
};

