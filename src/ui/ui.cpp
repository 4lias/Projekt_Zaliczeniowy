#include <SFML/Graphics.hpp>
#include "ui.h"
#include <cmath>
#include <iostream>

float expOutEase(float time)
{
    return 1-pow(2,(-10)*time);
}

void UI::displayHelloWorld()
{
    float speed = 0.5f;
    int queue = 0;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Snek", sf::Style::Default);
    sf::Clock clock;
    sf::Font font;
    sf::Font font2;
    sf::Texture tex;
    
    if(!font.loadFromFile("../../assets/fonts/HelpMe.ttf")){}
    if(!font2.loadFromFile("../../assets/fonts/IHATCS__.TTF")){}
    if(!tex.loadFromFile("../../assets/sprites/tf.png")){}
    
    sf::Text text;
    text.setFont(font);
    text.setString("Snek");
    text.setCharacterSize(300);
    text.setColor(sf::Color::Black);
    text.setOrigin(400, 100);
    text.setPosition(0,200);

    sf::Text text2;
    text2.setFont(font2);
    text2.setString("Gejm");
    text2.setCharacterSize(100);
    text2.setColor(sf::Color::Black);
    text2.setOrigin(100,50);
    text2.setPosition(960,670);

    sf::Sprite sprite;
    sprite.setTexture(tex);
    sprite.setOrigin(173, 144);
    sprite.setPosition(0, 0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White); // Wyczyszczenie okna na biało

        // Tutaj można dodać kod rysowania dodatkowych elementów
        
        window.draw(text);
        window.draw(sprite);
        window.draw(text2);
        window.display(); // Wyświetlenie zawartości okna

        sf::Time timer = clock.getElapsedTime();
        float time = timer.asSeconds();
        
        //sf::Vector2f snekPos = text.getPosition();
        //sf::Vector2f spritePos = sprite.getPosition();

        text.setPosition(960*expOutEase(speed*time), 150);
        sprite.setPosition(960*expOutEase((speed*time)-0.5f), 500);
        text2.setScale(expOutEase((speed*time)-1.5f),expOutEase((speed*time)-1.5f));
        
    }
}
