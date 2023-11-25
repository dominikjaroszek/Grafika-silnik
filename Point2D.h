#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "TransformableObject.h"
class PrimitiveRenderer;

/// Klasa reprezentuj¹ca punkt w dwuwymiarowej przestrzeni.
/// 
/// Klasa Point2D dziedziczy po klasie TransformableObject, co oznacza,¿e mo¿e byæ transformowana za pomoc¹ translacji, rotacji i skalowania.


class Point2D :public TransformableObject {
public:
    /// Konstruktor klasy Point2D.
    ///
    /// @param x Wartoœæ wspó³rzêdnej x punktu (domyœlnie 0.0f).
    /// @param y Wartoœæ wspó³rzêdnej y punktu(domyœlnie 0.0f).
    Point2D(float x = 0.0f, float y = 0.0f);
    /// Metoda przesuwaj¹ca punkt o okreœlone wartoœci.
    /// 
    /// @param dx Przesuniêcie wzd³u¿ osi X.
    /// @param dy Przesuniêcie wzd³u¿ osi Y.
    void translate(float dx, float dy) override;
    /// Metoda obracaj¹ca punkt o zadany k¹t.
    /// 
    /// @param angle K¹t obrotu w stopniach.
    void rotate(float angle) override;
    /// Metoda obracaj¹ca punkt o zadany k¹t.
    /// 
    /// @param angle K¹t obrotu w stopniach.
    void scale(float factor) override;
    /// Pobiera wspó³rzêdne punktu jako obiekt sf::Vector2f.
    /// 
    /// @return Wspó³rzêdne punktu jako obiekt sf::Vector2f.
    sf::Vector2f getCoordinates() ;
    /// Ustawia nowe wspó³rzêdne punktu.
    /// 
    /// @param newX Nowa wartoœæ wspó³rzêdnej x.
    /// @param newY Nowa wartoœæ wspó³rzêdnej y.
    void setCoordinates(float newX, float newY);
    /// Rysuje punkt przy u¿yciu danego PrimitiveRenderer.
    /// 
    /// @param renderer Obiekt do rysowania.
    /// @param color Kolor, który ma byæ u¿yty do rysowania punktu.
    void draw(PrimitiveRenderer &renderer, sf::Color color );
    /// Pobiera wartoœæ wspó³rzêdnej y punktu.
    /// 
    /// @return Wartoœæ wspó³rzêdnej y punktu.
    float getCoordinatesY();
    /// Pobiera wartoœæ wspó³rzêdnej x punktu.
    /// 
    /// @return Wartoœæ wspó³rzêdnej x punktu.
    float getCoordinatesX();

private:
    /// Wspó³rzêdna x punktu
    
    float x;
    /// Wspó³rzêdna y punktu
    float y;
};

