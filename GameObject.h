#pragma once
#include <SFML/Graphics.hpp>

/// Klasa reprezentuj�ca og�lny obiekt w grze.
///
/// Klasa GameObject jest abstrakcyjn� klas� bazow�, kt�ra zawiera podstawowe informacje o po�o�eniu obiektu w grze, takie jak wsp�rz�dne x i y.
class GameObject
{
private:
	///< Wsp�rz�dne po�o�enia obiektu w grze.
	sf::Vector2f location;
};

