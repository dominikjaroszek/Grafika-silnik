#pragma once

#include <SFML/Audio.hpp>

/// Klasa odpowiedzialna za odtwrzanie audio
/// 
/// Klasa Audio zawiera metody odtwarzaj�ce muzyk� w tle, d�wi�k skoku, d�wi�k zebrania wisienki, d�wi�k rzutu kamieniem, d�wi�k trafienia kamieniem oraz d�wi�k interakcji z przediwnikiem.
class Audio {
public:
    /// Metoda statyczna odtwarzaj�ca muzyk� w tle.
    static void playTheme(); 
    /// Metoda statyczna odtwarzaj�ca d�wi�k skoku.
    static void playJump();
    /// Metoda statyczna odtwarzaj�ca d�wi�k zebrania wi�ni.
    static void playCherry();
    /// Metoda statyczna odtwarzaj�ca d�wi�k rzutu kamieniem.
    static void playAttack();
    /// Metoda statyczna odtwarzaj�ca d�wi�k trafienia kamieniem.
    static void playHit();
    /// Metoda statyczna odtwarzaj�ca d�wi�k interakcji z przeciwnikiem.
    static void playAttacked();

private:
    /// Zmienna statyczna przechowuj�ca muzyk� t�a 
    static sf::Music theme;
    /// Zmienna statyczna kt�ra jest buforem dzwi�ku 
    static sf::SoundBuffer buffer;
    /// Zmienna statyczna przechowuj�ca odtwarzany d�wi�k
    static sf::Sound sound;
};
