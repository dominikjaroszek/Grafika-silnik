#pragma once

#include <SFML/Audio.hpp>

/// Klasa odpowiedzialna za odtwrzanie audio
/// 
/// Klasa Audio zawiera metody odtwarzaj¹ce muzykê w tle, dŸwiêk skoku, dŸwiêk zebrania wisienki, dŸwiêk rzutu kamieniem, dŸwiêk trafienia kamieniem oraz dŸwiêk interakcji z przediwnikiem.
class Audio {
public:
    /// Metoda statyczna odtwarzaj¹ca muzykê w tle.
    static void playTheme(); 
    /// Metoda statyczna odtwarzaj¹ca dŸwiêk skoku.
    static void playJump();
    /// Metoda statyczna odtwarzaj¹ca dŸwiêk zebrania wiœni.
    static void playCherry();
    /// Metoda statyczna odtwarzaj¹ca dŸwiêk rzutu kamieniem.
    static void playAttack();
    /// Metoda statyczna odtwarzaj¹ca dŸwiêk trafienia kamieniem.
    static void playHit();
    /// Metoda statyczna odtwarzaj¹ca dŸwiêk interakcji z przeciwnikiem.
    static void playAttacked();

private:
    /// Zmienna statyczna przechowuj¹ca muzykê t³a 
    static sf::Music theme;
    /// Zmienna statyczna która jest buforem dzwiêku 
    static sf::SoundBuffer buffer;
    /// Zmienna statyczna przechowuj¹ca odtwarzany dŸwiêk
    static sf::Sound sound;
};
