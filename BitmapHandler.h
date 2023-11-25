#pragma once
#include "MapData.h"

/// Klasa do obs³ugi bitmap.
///
/// Klasa BitmapHandler odpowiada za pobranie z pliku bitmapy, narysowanie jej na ekran oraz zapis bitmapy do pliku.
class BitmapHandler
{
public:
	/// Konstruktor klasy BitmapHandler.
	///
	/// @param window Referencja do obiektu sf::RenderWindow, w którym bitmapa jest renderowana.
	BitmapHandler(sf::RenderWindow& window);
	/// Metoda renderuj¹ca bitmapy t³a oraz pod³ogi na ekranie.
	void renderBitmap();
	/// Metoda zwracaj¹ca pozycjê i rozmiar po³ogi
	sf::FloatRect getSize();
	/// Rysuje na ekranie bitmape pobran¹ z pliku.
	/// 
	/// Rysuje w podanym miejscu na ekranie bitmape pobran¹ z pliku a nastêpnie przeskalowan¹.
	/// @param window Referencja do obiektu sf::RenderWindow, w którym bitmapa jest renderowana.
	/// @param path œcie¿ka do pliku z krórago pobierana jest bitmapa.
	/// @param PositionX Wspó³rzêdna X punktu od którego rysowana ma byæ bitmapa.
	/// @param PositionY Wspó³rzêdna Y punktu od którego rysowana ma byæ bitmapa.
	/// @param scaleX parametr okreœlaj¹cy wartoœæ skalowania w osi X.
	/// @param scaleY parametr okreœlaj¹cy wartoœæ skalowania w osi Y.
	static void drawFromFile(sf::RenderWindow& window, std::string path, float PositionX, float PositionY, float scaleX, float scaleY);
	/// Zapisuje bitmapê do pliku.
	/// 
	/// Zapisuje podan¹ bitmapê do pliku o podanej nazwie.
	/// @param FileName Nazwa pliku do którego zapisana ma zostaæ bitmapa.
	/// @param texture obraz zapisywany do pliku.
	static void saveToFile(std::string FileName, sf::Texture texture);
	

private:
	/// Referencja do obiektu sf::RenderWindow, w którym bitmapy s¹ renderowane.
	sf::RenderWindow& window;
	/// Obiekt sf::Image przechowuj¹cy obraz t³a.
	sf::Image bitmapImage;
	/// Obiekt sf::Texture przechowuj¹cy teksturê t³a.
	sf::Texture texture;
	/// Obiekt sf::Sprite przechowuj¹cy sprite t³a.
	sf::Sprite background;

	/// Obiekt sf::Image przechowuj¹cy obraz pod³ogi.
	sf::Image bitmapImageFloor;
	/// Obiekt sf::Texture przechowuj¹cy teksturê pod³ogi.
	sf::Texture textureFloor;
	/// Obiekt sf::Sprite przechowuj¹cy sprite pod³ogi.
	sf::Sprite floor;

};

