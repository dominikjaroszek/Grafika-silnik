#pragma once
#include "MapData.h"

/// Klasa do obs�ugi bitmap.
///
/// Klasa BitmapHandler odpowiada za pobranie z pliku bitmapy, narysowanie jej na ekran oraz zapis bitmapy do pliku.
class BitmapHandler
{
public:
	/// Konstruktor klasy BitmapHandler.
	///
	/// @param window Referencja do obiektu sf::RenderWindow, w kt�rym bitmapa jest renderowana.
	BitmapHandler(sf::RenderWindow& window);
	/// Metoda renderuj�ca bitmapy t�a oraz pod�ogi na ekranie.
	void renderBitmap();
	/// Metoda zwracaj�ca pozycj� i rozmiar po�ogi
	sf::FloatRect getSize();
	/// Rysuje na ekranie bitmape pobran� z pliku.
	/// 
	/// Rysuje w podanym miejscu na ekranie bitmape pobran� z pliku a nast�pnie przeskalowan�.
	/// @param window Referencja do obiektu sf::RenderWindow, w kt�rym bitmapa jest renderowana.
	/// @param path �cie�ka do pliku z kr�rago pobierana jest bitmapa.
	/// @param PositionX Wsp�rz�dna X punktu od kt�rego rysowana ma by� bitmapa.
	/// @param PositionY Wsp�rz�dna Y punktu od kt�rego rysowana ma by� bitmapa.
	/// @param scaleX parametr okre�laj�cy warto�� skalowania w osi X.
	/// @param scaleY parametr okre�laj�cy warto�� skalowania w osi Y.
	static void drawFromFile(sf::RenderWindow& window, std::string path, float PositionX, float PositionY, float scaleX, float scaleY);
	/// Zapisuje bitmap� do pliku.
	/// 
	/// Zapisuje podan� bitmap� do pliku o podanej nazwie.
	/// @param FileName Nazwa pliku do kt�rego zapisana ma zosta� bitmapa.
	/// @param texture obraz zapisywany do pliku.
	static void saveToFile(std::string FileName, sf::Texture texture);
	

private:
	/// Referencja do obiektu sf::RenderWindow, w kt�rym bitmapy s� renderowane.
	sf::RenderWindow& window;
	/// Obiekt sf::Image przechowuj�cy obraz t�a.
	sf::Image bitmapImage;
	/// Obiekt sf::Texture przechowuj�cy tekstur� t�a.
	sf::Texture texture;
	/// Obiekt sf::Sprite przechowuj�cy sprite t�a.
	sf::Sprite background;

	/// Obiekt sf::Image przechowuj�cy obraz pod�ogi.
	sf::Image bitmapImageFloor;
	/// Obiekt sf::Texture przechowuj�cy tekstur� pod�ogi.
	sf::Texture textureFloor;
	/// Obiekt sf::Sprite przechowuj�cy sprite pod�ogi.
	sf::Sprite floor;

};

