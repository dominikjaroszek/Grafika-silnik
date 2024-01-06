#pragma once

#include <SFML/Audio.hpp>

class Audio {
public:
    static void playTheme(); 
    static void playJump();
    static void playCherry();
    static void playAttack();
    static void playHit();
    static void playAttacked();

private:
    static sf::Music theme;
    static sf::SoundBuffer buffer;
    static sf::Sound sound;
};
