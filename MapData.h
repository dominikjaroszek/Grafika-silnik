#pragma once
#include <SFML/Graphics.hpp>
#include <Vector>
#include <Set>
#include <Map>

/// Klasa przechowuj�ca dane dotycz�ce mapy i wrog�w w grze.
///
/// Klasa MapData przechowuje informacje o platformach i wrogach dla r�nych poziom�w w grze.
class MapData
{
public:
	/// Konstruktor klasy MapData.
	MapData();
	/// Metoda zwracaj�ca dane o platformach dla danego poziomu.
	///
	/// @param ID Numer identyfikacyjny poziomu.
	/// @return Wektor par sf::Vector2f i std::string reprezentuj�cych pozycje i typy platform.
	std::vector<std::pair<sf::Vector2f, std::string>> getMap(int ID);
	/// Metoda zwracaj�ca dane o wrogach dla danego poziomu.
	///
	/// @param ID Numer identyfikacyjny poziomu.
	/// @return Wektor par sf::Vector2f i std::string reprezentuj�cych pozycje i typy wrog�w.
	std::vector<std::pair<sf::Vector2f, std::string>> getEnemy(int ID);
	/// Metoda zwracaj�ca zbi�r wszystkich dost�pnych typ�w map w grze.
	///
	/// @return Zbi�r std::string reprezentuj�cy unikalne typy map dost�pne w grze.
	std::set<std::string> getAllMaps();

private:
	/// Dane o platformach dla r�nych poziom�w.
	std::map<int, std::vector<std::pair<sf::Vector2f, std::string>>> maps;
	/// Dane o wrogach dla r�nych poziom�w.
	std::map<int, std::vector<std::pair<sf::Vector2f, std::string>>> enemies;

};

