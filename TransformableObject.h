#pragma once
#include "GameObject.h"

/// Klasa abstrakcyjna reprezentuj�ca obiekt gry podlegaj�cy transformacjom.
/// 
/// Klasa TransformableObject dziedziczy po klasie GameObject, co oznacza, �e jest to obiekt gry, kt�ry mo�e by� transformowany za pomoc� r�nych operacji
class TransformableObject : public GameObject
{
    /// Wirtualna metoda przemieszczaj�ca obiekt o okre�lone warto�ci.
    ///
    /// Metoda translate jest czysto wirtualna, co oznacza, �e nie ma domy�lnej implementacji w tej klasie bazowej.
    /// @param dx Przesuni�cie wzd�u� osi X.
    /// @param dy Przesuni�cie wzd�u� osi Y.
    virtual void translate(float dx, float dy) = 0;
    /// Wirtualna metoda obracaj�ca obiekt o zadany k�t.
    ///
    /// @param angle K�t obrotu w stopniach.
    virtual void rotate(float angle) = 0;
    /// Wirtualna metoda skaluj�ca obiekt o okre�lony wsp�czynnik.
    ///
    /// @param factor Wsp�czynnik skalowania.
    virtual void scale(float factor) = 0;
};

