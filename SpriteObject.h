#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"
/// Klasa reprezentuj�ca animowane obiekty bitmap.
///
/// Klas� bazow� dla wszystkich obiekt�w gry, kt�re mog� zosta� narysowanez u�yciem bitmap, i kt�re mog� by� animowane na zasadzie wykorzystania sprite��w. Klasa SpriteObject dziedziczy jednocze�nie po klasach BitmapObject i AnimatedObject
class SpriteObject: public BitmapObject, public AnimatedObject
{

};

