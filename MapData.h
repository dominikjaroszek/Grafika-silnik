#pragma once
#include <SFML/Graphics.hpp>
#include <Vector>
#include <Set>
#include <Map>

/// Klasa przechowuj¹ca dane dotycz¹ce mapy i wrogów w grze.
///
/// Klasa MapData przechowuje informacje o platformach i wrogach dla ró¿nych poziomów w grze.
class MapData
{
public:
	/// Konstruktor klasy MapData.
	MapData();
	/// Metoda zwracaj¹ca dane o platformach dla danego poziomu.
	///
	/// @param ID Numer identyfikacyjny poziomu.
	/// @return Wektor par sf::Vector2f i std::string reprezentuj¹cych pozycje i typy platform.
	std::vector<std::pair<sf::Vector2f, std::string>> getMap(int ID);
	/// Metoda zwracaj¹ca dane o wrogach dla danego poziomu.
	///
	/// @param ID Numer identyfikacyjny poziomu.
	/// @return Wektor par sf::Vector2f i std::string reprezentuj¹cych pozycje i typy wrogów.
	std::vector<std::pair<sf::Vector2f, std::string>> getEnemy(int ID);
	/// Metoda zwracaj¹ca zbiór wszystkich dostêpnych typów map w grze.
	///
	/// @return Zbiór std::string reprezentuj¹cy unikalne typy map dostêpne w grze.
	std::set<std::string> getAllMaps();

private:
	/// Dane o platformach dla ró¿nych poziomów.
	std::map<int, std::vector<std::pair<sf::Vector2f, std::string>>> maps;
	/// Dane o wrogach dla ró¿nych poziomów.
	std::map<int, std::vector<std::pair<sf::Vector2f, std::string>>> enemies;

};

