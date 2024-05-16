#include <SFML/Graphics.hpp>
#include "ui.h"
#include <cmath>
#include <numbers>
#include <iostream>

float expOutEase(float time, float delay = 0)
{
    float ease = 1-pow(2,(-10)*(time-delay));
    if(ease < 0){
        return 0;
    }else{
        return ease;
    }
}
float sinInOutEase(float time)
{
    return sinf(time)*0.5f + 0.5f;
}

void UI::displayGame()
{
    float speed = 0.5f;
    int screenDimensions[] = {1920, 1080};
    int recAmount = 122;

    sf::RenderWindow window(sf::VideoMode(screenDimensions[0], screenDimensions[1]), "Snek", sf::Style::Default);
    sf::Clock clock;
    sf::Clock clock2;
    sf::Font font;
    sf::Font font2;
    sf::Texture tex;

    std::vector<sf::RectangleShape> rec(recAmount);
    int posX = screenDimensions[0]*0.5f, posY = screenDimensions[1]*0.5f, a=0, j=0, b=1;
    rec[0].setPosition(posX, posY);
    rec[0].setSize(sf::Vector2f(200, 200));
    rec[0].setFillColor(sf::Color(0,0,0,0));
    rec[0].setOrigin(100, 100);
            
    for(int n=0; n<=21; n++)
    {
        int modN = n%2;
        j = j + modN-b;

        int dirX = round(cos(M_PI*0.5f*n));
        int dirY = round(sin(M_PI*0.5f*n));
    
        for(int i=0; i<=j; i++) {
            a++;
            posX = posX + dirX*200;
            posY = posY + dirY*200;

            rec[a].setSize(sf::Vector2f(200, 200));
            rec[a].setFillColor(sf::Color(0,0,0,0));
            rec[a].setOrigin(100, 100);
            rec[a].setPosition(posX, posY);
        }
        b=0;
    }
    
    if(!font.loadFromFile("../../assets/fonts/HelpMe.ttf")){}
    if(!font2.loadFromFile("../../assets/fonts/IHATCS__.TTF")){}
    if(!tex.loadFromFile("../../assets/sprites/tf.png")){}

    sf::Text text;
    text.setFont(font);
    text.setString("Snek");
    text.setCharacterSize(300);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getLocalBounds().width*0.5f, text.getLocalBounds().height*0.5f);
    text.setPosition(0,200);

    sf::Text text2;
    text2.setFont(font2);
    text2.setString("Press Enter");
    text2.setCharacterSize(100);
    text2.setFillColor(sf::Color::Black);
    text2.setOrigin(text2.getLocalBounds().width*0.5f,text2.getLocalBounds().height*0.5f);
    text2.setPosition(screenDimensions[0]*0.5f,screenDimensions[1]*0.5f+200);

    sf::Sprite sprite;
    sprite.setTexture(tex);
    sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    sprite.setPosition(-200, 0);

    //Update
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(81, 186, 28)); // Wyczyszczenie okna na zielono

        // Tutaj można dodać kod rysowania dodatkowych elementów
        
        //window.draw(text);
        //window.draw(sprite);
        //window.draw(text2);
        for(int i=0;i<recAmount;i++)
            window.draw(rec[i]);

        window.display(); // Wyświetlenie zawartości okna

        sf::Time timer = clock.getElapsedTime();
        float time = timer.asSeconds();

        text.setPosition(screenDimensions[0]*0.5f*expOutEase(speed*time), 150);
        sprite.setPosition((screenDimensions[0]*0.5f+200)*expOutEase((speed*time), 0.5f)-200, 500);
        text2.setScale(expOutEase((speed*time), 1),expOutEase((speed*time), 1));

        text2.setFillColor(sf::Color(0,0,0,255*sinInOutEase(time*3)));

        for(int i=0; i<recAmount; i++){
                    rec[i].setFillColor(sf::Color(0,0,0,255*expOutEase(time,0.02f*i)));
                }

        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.scancode == sf::Keyboard::Scan::Enter)
            {
                clock2.restart();
                sf::Time timer2 = clock2.getElapsedTime();
                float time2 = timer.asSeconds();
                /*for(int i=0; i<recAmount; i++){
                    rec[i].setFillColor(sf::Color(0,0,0,255*expOutEase(time2*0.1f,0.5f*i)));
                }*/
            }
            
        }
    }
}
