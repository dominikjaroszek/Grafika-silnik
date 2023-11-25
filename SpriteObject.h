#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"
/// Klasa reprezentuj¹ca animowane obiekty bitmap.
///
/// Klas¹ bazow¹ dla wszystkich obiektów gry, które mog¹ zostaæ narysowanez u¿yciem bitmap, i które mog¹ byæ animowane na zasadzie wykorzystania sprite’ów. Klasa SpriteObject dziedziczy jednoczeœnie po klasach BitmapObject i AnimatedObject
class SpriteObject: public BitmapObject, public AnimatedObject
{

};

