#pragma once
#include "GameObject.h"

/// Klasa abstrakcyjna reprezentuj¹ca obiekt gry podlegaj¹cy transformacjom.
/// 
/// Klasa TransformableObject dziedziczy po klasie GameObject, co oznacza, ¿e jest to obiekt gry, który mo¿e byæ transformowany za pomoc¹ ró¿nych operacji
class TransformableObject : public GameObject
{
    /// Wirtualna metoda przemieszczaj¹ca obiekt o okreœlone wartoœci.
    ///
    /// Metoda translate jest czysto wirtualna, co oznacza, ¿e nie ma domyœlnej implementacji w tej klasie bazowej.
    /// @param dx Przesuniêcie wzd³u¿ osi X.
    /// @param dy Przesuniêcie wzd³u¿ osi Y.
    virtual void translate(float dx, float dy) = 0;
    /// Wirtualna metoda obracaj¹ca obiekt o zadany k¹t.
    ///
    /// @param angle K¹t obrotu w stopniach.
    virtual void rotate(float angle) = 0;
    /// Wirtualna metoda skaluj¹ca obiekt o okreœlony wspó³czynnik.
    ///
    /// @param factor Wspó³czynnik skalowania.
    virtual void scale(float factor) = 0;
};

