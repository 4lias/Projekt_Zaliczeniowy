#include <SFML/Graphics.hpp>
#include "ui.h"
#include <iostream>

void UI::displayHelloWorld()
{
    float speed = 0.1f;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Snek", sf::Style::Default);
    sf::Clock timer;
    sf::Font font;
    if(!font.loadFromFile("../../assets/fonts/HelpMe.ttf"))
        std::cout<<"error";

    
    sf::Text text;
    text.setFont(font);
    text.setString("Snek");
    text.setCharacterSize(300);
    text.setColor(sf::Color::Black);
    text.setPosition(0,100);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White); // Wyczyszczenie okna na biało

        // Tutaj można dodać kod rysowania dodatkowych elementów
        
        window.draw(text);
        window.display(); // Wyświetlenie zawartości okna

        sf::Time time = timer.getElapsedTime();
        //std::cout << time.asSeconds() << std::endl;

        
        sf::Vector2f snekPos = text.getPosition();

        float deltaTime = time.asSeconds();
        if(snekPos.x <= 1000)
            text.move(speed*deltaTime, 0);
    }
}
