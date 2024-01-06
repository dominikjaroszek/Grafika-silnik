#include "Audio.h"

sf::Music Audio::theme;
sf::SoundBuffer Audio::buffer;
sf::Sound Audio::sound;

void Audio::playTheme() {
    if (!theme.openFromFile("Audio/Theme.mp3")) {
        // Handle error loading theme audio
    }
    theme.setVolume(20);
    theme.setLoop(true);
    theme.play();
}

void Audio::playJump() {
    if (buffer.loadFromFile("Audio/jump.wav")) {
        sound.setBuffer(buffer);
        sound.play();
    }
}

void Audio::playCherry() {
    if (buffer.loadFromFile("Audio/cherry.wav")) {
        sound.setBuffer(buffer);
        sound.play();
    }
}

void Audio::playAttack() {
    if (buffer.loadFromFile("Audio/attack.wav")) {
        sound.setBuffer(buffer);
        sound.play();
    }
}

void Audio::playHit() {
    if (buffer.loadFromFile("Audio/hit.wav")) {
        sound.setBuffer(buffer);
        sound.play();
    }
}

void Audio::playAttacked() {
    static sf::Clock delayClock;
    static bool delayStarted = false;

    if (!delayStarted) {
        delayClock.restart();
        delayStarted = true;
    }

    if (delayClock.getElapsedTime().asSeconds() > 1.0) { // 1-second delay
        if (buffer.loadFromFile("Audio/attacked.wav")) {
            sound.setBuffer(buffer);
            sound.play();
            delayStarted = false; // Reset delay status for the next play
        }
    }
}