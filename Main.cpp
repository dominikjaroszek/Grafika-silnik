#include <SFML/Graphics.hpp>

class Engine {
public:
    static Engine& getInstance() {
        static Engine instance;
        return instance;
    }

    void init(int screenWidth, int screenHeight,  std::string windowTitle) {
        if (!initialized) {
            window.create(sf::VideoMode(screenWidth, screenHeight), windowTitle);
            window.setFramerateLimit(60); // Limit klatek na sekund�
            initialized = true;
        }
    }
    void setFramesPerSecond(int fps) {
        window.setFramerateLimit(fps); // Ustaw liczb� klatek na sekund�
    }

    void setWindowSize(int width, int height) {
        window.setSize(sf::Vector2u(width, height));
    }

    void setFullscreen(bool fullscreen) {
        if (fullscreen) {
            window.create(sf::VideoMode::getFullscreenModes()[0], "Fullscreen");
        }
        else {
            window.create(sf::VideoMode(window.getSize().x, window.getSize().y), "Windowed");
        }
    }
    void enableMouseInput() {
        window.setMouseCursorVisible(true); // W��cz widoczno�� kursora myszy
        window.setMouseCursorGrabbed(true); // Przechwytuj kursor myszy

        // Ustaw kursor myszy na strza�k�
        sf::Cursor cursor;
        if (cursor.loadFromSystem(sf::Cursor::Arrow))
        {
            window.setMouseCursor(cursor);
        }

    }

    void handleInput() {
        // Obs�uga klawiatury i myszy
    }

    void update() {
        // Aktualizacja logiki gry
    }

    void clearScreen(const sf::Color& color) {
        window.clear(color);
    }

    void draw() {
        // Rysowanie obiekt�w gry
    }

    void display() {
        window.display();
    }

    void run() {
        sf::Clock clock;
        float deltaTime = 0.0f;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            deltaTime = clock.restart().asSeconds();

            handleInput();
            update();
            clearScreen(sf::Color::Black);
            draw();
            display();
        }

        // Zamkni�cie gry
        window.close();
    }

private:
    sf::RenderWindow window;
    bool initialized;
     

    Engine() 
    {
        initialized = false;
    }

    ~Engine() {
        // Deinicjacja (np. sprz�tanie pami�ci, zamkni�cie plik�w itp.)
    }

    // Zablokowanie mo�liwo�ci kopiowania i przypisania obiektu klasy
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
};

int main() {
    Engine& gameEngine = Engine::getInstance();
    gameEngine.init(800, 600, "Game Window");
    gameEngine.run();

    return 0;
}