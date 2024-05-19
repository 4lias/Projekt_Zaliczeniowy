#include "ui.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

void UI::displayGame() {
    sf::RenderWindow window(sf::VideoMode(screenDimensions[0], screenDimensions[1]), "Snek", sf::Style::Default);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(0,0,0));

        window.display();
    }
}
