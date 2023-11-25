#pragma once
#include <SFML/Graphics.hpp>
#include <Set>
#include "Enemy.h"
#include "MapData.h"
#include <set>

/// Klasa zarz�dzaj�ca mapami w grze.
///
/// Klasa MapHandler odpowiedzialna jest za wczytywanie, renderowanie oraz obs�ug� map w grze.

class MapHandler
{
public:
	/// Konstruktor klasy MapHandler.
	///
	/// @param window Referencja do obiektu sf::RenderWindow, w kt�rym obiekty s� renderowane.
	MapHandler(sf::RenderWindow& window);
	/// Metoda ustawiaj�ca indeks aktualnej mapy.
	/// 
	/// @param index Nowy indeks mapy.
	void setMapIndex(int index);
	///Metoda zwracaj�ca wektor wska�nik�w do obiekt�w Enemy stworzonych na danej mapie.
	///
	/// @return Wektor wska�nik�w do obiekt�w Enemy.
	std::vector<Enemy*> getEnemies();
	/// Metoda usuwaj�ca obiekt wroga z danej mapy.
	///
	/// @param index Indeks obiektu wroga do usuni�cia.
	void removeEnemy(int index);
	/// Metoda renderuj�ca bitmap� mapy na ekranie.
	///
	/// Renderuje bitmap� mapy na ekranie, w tym numer poziomu i liczb� poziom�w. U�ywa wcze�niej wczytanej czcionki i tekstury.
	void renderBitmap();
	/// Metoda zwracaj�ca wektor obiekt�w sf::Sprite reprezentuj�cych platformy na danej mapie.
	///
	/// @return Wektor obiekt�w sf::Sprite reprezentuj�cych platformy.
	std::vector<sf::Sprite> getPlatformSprites();
	

private:
	/// Referencja do obiektu sf::RenderWindow, w kt�rym obiekty s� renderowane.
	sf::RenderWindow& window;
	/// Obiekt przechowuj�cy dane o mapach.
	MapData mapData;
	/// Wektor przechowuj�cy informacje o pozycji i nazwie platform na mapie.
	std::vector<std::pair<sf::Vector2f, std::string>> map;
	/// Licznik aktualnej mapy.
	int mapCounter;
	/// Wektor przechowuj�cy informacje o pozycji i nazwie wrog�w na mapie.
	std::vector<std::pair<sf::Vector2f, std::string>> enemies;
	/// Wektor wska�nik�w do obiekt�w wroga stworzonych na danej mapie.
	std::vector<Enemy*> createdEnemies;
	/// Zbi�r przechowuj�cy indeksy map, na kt�rych wrogowie zostali ju� wyrenderowani.
	std::set<int> enemiesRenderedOnMap;
	/// Wektor obiekt�w sf::Sprite reprezentuj�cych platformy na danej mapie.
	std::vector<sf::Sprite> platformSprites;
	/// Tekst u�ywany do wy�wietlenia informacji o poziomie gry.
	sf::Text text;
	/// Czcionka u�ywana do tekstu.
	sf::Font font;
	///Metoda wczytuj�ca tekstury map z plik�w.png.
	///
	/// Wczytuje tekstury z plik�w .png i przechowuje je w mapie tekstur mapTextures. Wy�wietla b��d na konsoli w przypadku niepowodzenia wczytywania pliku.
	void loadTextures();
	/// Zbi�r przechowuj�cy nazwy plik�w .png z teksturami map.
	std::set<std::string> imagesSet;
	/// Mapa przechowuj�ca tekstury map, gdzie kluczami s� nazwy plik�w .png.
	std::map<std::string, sf::Texture> mapTextures;

	/// Metoda renderuj�ca platformy na ekranie.
	///
	/// Renderuje platformy na ekranie na podstawie wczytanej mapy.
	void renderPlatforms();
};

