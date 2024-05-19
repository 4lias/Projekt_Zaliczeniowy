#include "ui.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

void UI::displayGame() {
    sf::RenderWindow window(sf::VideoMode(screenDimensions[0], screenDimensions[1]), "Snek", sf::Style::Default);
    sf::Clock clock;
    sf::Font font;
    sf::Font font2;

    const int recAmount = 10;
    std::vector<sf::RectangleShape> rec(recAmount);

    rec[0].setSize(sf::Vector2f(200, 200));
    rec[0].setFillColor(sf::Color(0, 0, 0, 0));

    if (!font.loadFromFile("../../assets/fonts/HelpMe.ttf")) {}
    if (!font2.loadFromFile("../../assets/fonts/IHATCS__.TTF")) {}

    sf::Text text;
    text.setFont(font);
    text.setString("Example Text");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    sf::Text text2;
    text2.setFont(font2);
    text2.setString("Another Text");
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(81, 186, 28));

        text.setPosition(screenDimensions[0] * 0.5f, 150);

        for (int i = 0; i < recAmount; ++i) {
            rec[i].setFillColor(sf::Color(0, 0, 0, 255));
        }

        window.display();
    }
}
