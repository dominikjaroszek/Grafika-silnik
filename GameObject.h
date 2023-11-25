#pragma once
#include <SFML/Graphics.hpp>

/// Klasa reprezentuj¹ca ogólny obiekt w grze.
///
/// Klasa GameObject jest abstrakcyjn¹ klas¹ bazow¹, która zawiera podstawowe informacje o po³o¿eniu obiektu w grze, takie jak wspó³rzêdne x i y.
class GameObject
{
private:
	///< Wspó³rzêdne po³o¿enia obiektu w grze.
	sf::Vector2f location;
};

