#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <set>
#include "LineSegment.h"
#include "Point2D.h"

class LineSegment;
/// Klasa do rysowania podstawowych kszta�t�w graficznych w oknie SFML
/// 
/// Klasa PrimitiveRenderer umo�liwia rysowanie r�nych podstawowych kszta�t�w
/// graficznych, takich jak prostok�ty, okr�gi, linie, punkty, elipsy, wielok�ty,
/// a tak�e wykonuje operacje wype�niania kszta�t�w i sprawdzania przeci�� odcink�w.
/// 
class PrimitiveRenderer {
public:
    /// Konstruktor klasy PrimitiveRenderer.
    /// 
    /// @param window Referencja do obiektu sf::RenderWindow, w kt�rym b�d� rysowane kszta�ty.
    PrimitiveRenderer(sf::RenderWindow& window);
    /// Rysuje prostok�t w oknie.
    ///
    /// @param position Pozycja pocz�tkowa prostok�ta.
    /// @param size Rozmiar prostok�ta.
    /// @param color Kolor prostok�ta.
    void drawRectangle( sf::Vector2f position,   sf::Vector2f size,   sf::Color color);
    /// Rysuje okr�g w oknie.
    ///
    /// @param position Pozycja �rodka okr�gu.
    /// @param radius Promie� okr�gu.
    /// @param color Kolor okr�gu.
    void drawCircle( sf::Vector2f position, float radius,   sf::Color color);
    /// Rysuje lini� 
    ///
    /// @param point1 Pocz�tkowy punkt linii.
    /// @param point2 Ko�cowy punkt linii.
    /// @param color Kolor linii.
    void drawLine( sf::Vector2f point1,  sf::Vector2f point2,   sf::Color color);
    /// Rysuje lini� zgodnie z instrukcj� zadania.
    ///
    /// @param point1 Pocz�tkowy punkt linii.
    /// @param point2 Ko�cowy punkt linii.
    /// @param color Kolor linii.
    void drawLineInstrukcja(  sf::Vector2f point1,   sf::Vector2f point2,   sf::Color color);
    /// Rysuje punkt w oknie.
    ///
    /// @param point Wsp�rz�dne punktu.
    /// @param color Kolor punktu.
    void drawPoint(sf::Vector2f point, sf::Color color);
    /// Rysuje elips� zgodnie z instrukcj� zada�.
    ///
    /// @param point Punkt centralny elipsy.
    /// @param Rx Promie� elipsy wzd�u� osi X.
    /// @param Ry Promie� elipsy wzd�u� osi Y.
    /// @param color Kolor elipsy.
    void drawElipseInstrukcja(sf::Vector2f point, float Rx, float Ry, sf::Color color);
    /// Rysuje elips� wype�nion� kolorem.
    ///
    /// @param point Punkt centralny elipsy.
    /// @param Rx Promie� elipsy wzd�u� osi X.
    /// @param Ry Promie� elipsy wzd�u� osi Y.
    /// @param color Kolor elipsy.
    void drawFilledElipse(sf::Vector2f point, float Rx, float Ry, sf::Color color);
    /// Wype�nia kszta�t, zaczynaj�c od danego punktu.
    ///
    /// @param point Pocz�tkowy punkt do wype�nienia.
    /// @param fillColor Kolor wype�nienia.
    /// @param borderColor Kolor obramowania.
    void boundryFill(sf::Vector2f point, sf::Color fillColor, sf::Color borderColor);
    /// Algorytm wype�niania obszaru.
    ///
    /// @param point Pocz�tkowy punkt do wype�nienia.
    /// @param fillColor Kolor wype�nienia.
    
    void floodFill(sf::Vector2f point, sf::Color fillColor);
    /// Rysuje �aman� sk�adaj�c� si� z punkt�w
    ///
    /// @param points Wektor punkt�w �amanej.
    /// @param color Kolor �amanej.
    /// @param closed Okre�la, czy �amana ma by� zamkni�ta.
    void brokeLine(std::vector<Point2D> points, sf::Color color, bool closed);
    /// Rysuje okr�g zgodnie z instrukcj� zadania.
    ///
    /// @param point Pocz�tkowy punkt okr�gu
    /// @param R Promie� okr�gu.
    /// @param color Kolor okr�gu.
    void drawCircleInstrukcja(sf::Vector2f point, float R, sf::Color color);
    /// Sprawdza, czy dwa odcinki przecinaj� si�.
    ///
    /// @param A Pierwszy odcinek.
    /// @param B Drugi odcinek.
    /// @return True, je�li odcinki si� przecinaj�, False w przeciwnym razie.
    bool segmentsIntersect(LineSegment& A, LineSegment& B);
    /// Rysuje wielok�t zdefiniowany przez odcinki.
    ///
    /// @param lines Wektor odcink�w definiuj�cych wielok�t.
    /// @param color Kolor wielok�ta.
    void drawPolygon(std::vector<LineSegment>& lines, sf::Color color);
    /// Rysuje wype�niony kolorem wielok�t zdefiniowany przez odcinki.
    ///
    /// @param lines Wektor odcink�w definiuj�cych wielok�t.
    /// @param color Kolor wielok�ta.
    void drawFilledPolygon(std::vector<LineSegment>& lines, sf::Color color);
    /// Rysuje wi�ni� z u�yceim metod zdefiniowanych w klasie PrimitiveRenderer.
    ///
    /// @param position pozycja na ekranie w narysowana ma zosta� wi�nia.
    void drawCherry(sf::Vector2f position);
    /// Rysuje drzewo z u�yceim metod zdefiniowanych w klasie PrimitiveRenderer.
    ///
    /// @param position pozycja na ekranie w narysowana ma zosta� drzewo.
    void drawTree(sf::Vector2f position);
private:
    /// Referencja do obiektu okna, w kt�rym rysowane s� kszta�ty.
    sf::RenderWindow& window;
};