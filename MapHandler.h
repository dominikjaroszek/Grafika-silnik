#pragma once
#include <SFML/Graphics.hpp>
#include <Set>
#include "Enemy.h"
#include "MapData.h"
#include <set>

/// Klasa zarz¹dzaj¹ca mapami w grze.
///
/// Klasa MapHandler odpowiedzialna jest za wczytywanie, renderowanie oraz obs³ugê map w grze.

class MapHandler
{
public:
	/// Konstruktor klasy MapHandler.
	///
	/// @param window Referencja do obiektu sf::RenderWindow, w którym obiekty s¹ renderowane.
	MapHandler(sf::RenderWindow& window);
	/// Metoda ustawiaj¹ca indeks aktualnej mapy.
	/// 
	/// @param index Nowy indeks mapy.
	void setMapIndex(int index);
	///Metoda zwracaj¹ca wektor wskaŸników do obiektów Enemy stworzonych na danej mapie.
	///
	/// @return Wektor wskaŸników do obiektów Enemy.
	std::vector<Enemy*> getEnemies();
	/// Metoda usuwaj¹ca obiekt wroga z danej mapy.
	///
	/// @param index Indeks obiektu wroga do usuniêcia.
	void removeEnemy(int index);
	/// Metoda renderuj¹ca bitmapê mapy na ekranie.
	///
	/// Renderuje bitmapê mapy na ekranie, w tym numer poziomu i liczbê poziomów. U¿ywa wczeœniej wczytanej czcionki i tekstury.
	void renderBitmap();
	/// Metoda zwracaj¹ca wektor obiektów sf::Sprite reprezentuj¹cych platformy na danej mapie.
	///
	/// @return Wektor obiektów sf::Sprite reprezentuj¹cych platformy.
	std::vector<sf::Sprite> getPlatformSprites();
	

private:
	/// Referencja do obiektu sf::RenderWindow, w którym obiekty s¹ renderowane.
	sf::RenderWindow& window;
	/// Obiekt przechowuj¹cy dane o mapach.
	MapData mapData;
	/// Wektor przechowuj¹cy informacje o pozycji i nazwie platform na mapie.
	std::vector<std::pair<sf::Vector2f, std::string>> map;
	/// Licznik aktualnej mapy.
	int mapCounter;
	/// Wektor przechowuj¹cy informacje o pozycji i nazwie wrogów na mapie.
	std::vector<std::pair<sf::Vector2f, std::string>> enemies;
	/// Wektor wskaŸników do obiektów wroga stworzonych na danej mapie.
	std::vector<Enemy*> createdEnemies;
	/// Zbiór przechowuj¹cy indeksy map, na których wrogowie zostali ju¿ wyrenderowani.
	std::set<int> enemiesRenderedOnMap;
	/// Wektor obiektów sf::Sprite reprezentuj¹cych platformy na danej mapie.
	std::vector<sf::Sprite> platformSprites;
	/// Tekst u¿ywany do wyœwietlenia informacji o poziomie gry.
	sf::Text text;
	/// Czcionka u¿ywana do tekstu.
	sf::Font font;
	///Metoda wczytuj¹ca tekstury map z plików.png.
	///
	/// Wczytuje tekstury z plików .png i przechowuje je w mapie tekstur mapTextures. Wyœwietla b³¹d na konsoli w przypadku niepowodzenia wczytywania pliku.
	void loadTextures();
	/// Zbiór przechowuj¹cy nazwy plików .png z teksturami map.
	std::set<std::string> imagesSet;
	/// Mapa przechowuj¹ca tekstury map, gdzie kluczami s¹ nazwy plików .png.
	std::map<std::string, sf::Texture> mapTextures;

	/// Metoda renderuj¹ca platformy na ekranie.
	///
	/// Renderuje platformy na ekranie na podstawie wczytanej mapy.
	void renderPlatforms();
};

