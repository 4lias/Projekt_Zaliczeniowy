#include <SFML/Graphics.hpp>

class UI {
public:
    void displayLevel(int level) {
        // implementacja
    }

    void displayPoints(int points) {
        // implementacja
    }

    void displayBoard() {
        // implementacja
    }

    void displaySnake() {
        // implementacja
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White); // Wyczyszczenie okna na biało

        // Tutaj można dodać kod rysowania dodatkowych elementów

        window.display(); // Wyświetlenie zawartości okna
    }

    return 0;
}
