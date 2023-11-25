#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <set>
#include "LineSegment.h"
#include "Point2D.h"

class LineSegment;
/// Klasa do rysowania podstawowych kszta³tów graficznych w oknie SFML
/// 
/// Klasa PrimitiveRenderer umo¿liwia rysowanie ró¿nych podstawowych kszta³tów
/// graficznych, takich jak prostok¹ty, okrêgi, linie, punkty, elipsy, wielok¹ty,
/// a tak¿e wykonuje operacje wype³niania kszta³tów i sprawdzania przeciêæ odcinków.
/// 
class PrimitiveRenderer {
public:
    /// Konstruktor klasy PrimitiveRenderer.
    /// 
    /// @param window Referencja do obiektu sf::RenderWindow, w którym bêd¹ rysowane kszta³ty.
    PrimitiveRenderer(sf::RenderWindow& window);
    /// Rysuje prostok¹t w oknie.
    ///
    /// @param position Pozycja pocz¹tkowa prostok¹ta.
    /// @param size Rozmiar prostok¹ta.
    /// @param color Kolor prostok¹ta.
    void drawRectangle( sf::Vector2f position,   sf::Vector2f size,   sf::Color color);
    /// Rysuje okr¹g w oknie.
    ///
    /// @param position Pozycja œrodka okrêgu.
    /// @param radius Promieñ okrêgu.
    /// @param color Kolor okrêgu.
    void drawCircle( sf::Vector2f position, float radius,   sf::Color color);
    /// Rysuje liniê 
    ///
    /// @param point1 Pocz¹tkowy punkt linii.
    /// @param point2 Koñcowy punkt linii.
    /// @param color Kolor linii.
    void drawLine( sf::Vector2f point1,  sf::Vector2f point2,   sf::Color color);
    /// Rysuje liniê zgodnie z instrukcj¹ zadania.
    ///
    /// @param point1 Pocz¹tkowy punkt linii.
    /// @param point2 Koñcowy punkt linii.
    /// @param color Kolor linii.
    void drawLineInstrukcja(  sf::Vector2f point1,   sf::Vector2f point2,   sf::Color color);
    /// Rysuje punkt w oknie.
    ///
    /// @param point Wspó³rzêdne punktu.
    /// @param color Kolor punktu.
    void drawPoint(sf::Vector2f point, sf::Color color);
    /// Rysuje elipsê zgodnie z instrukcj¹ zadañ.
    ///
    /// @param point Punkt centralny elipsy.
    /// @param Rx Promieñ elipsy wzd³u¿ osi X.
    /// @param Ry Promieñ elipsy wzd³u¿ osi Y.
    /// @param color Kolor elipsy.
    void drawElipseInstrukcja(sf::Vector2f point, float Rx, float Ry, sf::Color color);
    /// Rysuje elipsê wype³nion¹ kolorem.
    ///
    /// @param point Punkt centralny elipsy.
    /// @param Rx Promieñ elipsy wzd³u¿ osi X.
    /// @param Ry Promieñ elipsy wzd³u¿ osi Y.
    /// @param color Kolor elipsy.
    void drawFilledElipse(sf::Vector2f point, float Rx, float Ry, sf::Color color);
    /// Wype³nia kszta³t, zaczynaj¹c od danego punktu.
    ///
    /// @param point Pocz¹tkowy punkt do wype³nienia.
    /// @param fillColor Kolor wype³nienia.
    /// @param borderColor Kolor obramowania.
    void boundryFill(sf::Vector2f point, sf::Color fillColor, sf::Color borderColor);
    /// Algorytm wype³niania obszaru.
    ///
    /// @param point Pocz¹tkowy punkt do wype³nienia.
    /// @param fillColor Kolor wype³nienia.
    
    void floodFill(sf::Vector2f point, sf::Color fillColor);
    /// Rysuje ³aman¹ sk³adaj¹c¹ siê z punktów
    ///
    /// @param points Wektor punktów ³amanej.
    /// @param color Kolor ³amanej.
    /// @param closed Okreœla, czy ³amana ma byæ zamkniêta.
    void brokeLine(std::vector<Point2D> points, sf::Color color, bool closed);
    /// Rysuje okr¹g zgodnie z instrukcj¹ zadania.
    ///
    /// @param point Pocz¹tkowy punkt okrêgu
    /// @param R Promieñ okrêgu.
    /// @param color Kolor okrêgu.
    void drawCircleInstrukcja(sf::Vector2f point, float R, sf::Color color);
    /// Sprawdza, czy dwa odcinki przecinaj¹ siê.
    ///
    /// @param A Pierwszy odcinek.
    /// @param B Drugi odcinek.
    /// @return True, jeœli odcinki siê przecinaj¹, False w przeciwnym razie.
    bool segmentsIntersect(LineSegment& A, LineSegment& B);
    /// Rysuje wielok¹t zdefiniowany przez odcinki.
    ///
    /// @param lines Wektor odcinków definiuj¹cych wielok¹t.
    /// @param color Kolor wielok¹ta.
    void drawPolygon(std::vector<LineSegment>& lines, sf::Color color);
    /// Rysuje wype³niony kolorem wielok¹t zdefiniowany przez odcinki.
    ///
    /// @param lines Wektor odcinków definiuj¹cych wielok¹t.
    /// @param color Kolor wielok¹ta.
    void drawFilledPolygon(std::vector<LineSegment>& lines, sf::Color color);
    /// Rysuje wiœniê z u¿yceim metod zdefiniowanych w klasie PrimitiveRenderer.
    ///
    /// @param position pozycja na ekranie w narysowana ma zostaæ wiœnia.
    void drawCherry(sf::Vector2f position);
    /// Rysuje drzewo z u¿yceim metod zdefiniowanych w klasie PrimitiveRenderer.
    ///
    /// @param position pozycja na ekranie w narysowana ma zostaæ drzewo.
    void drawTree(sf::Vector2f position);
private:
    /// Referencja do obiektu okna, w którym rysowane s¹ kszta³ty.
    sf::RenderWindow& window;
};