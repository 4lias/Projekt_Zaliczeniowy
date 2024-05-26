#include "controller.h"
#include "../ui/ui.h"
#include <SFML/Graphics.hpp>

int Controller::launch() {
    
    Board board;
    Snake snake;
    UI ui;
    bool startGame = false;

    ui.displayStartScreen();

    if (!board.generate(board, snake)) {
        return -1;
    }
    //create game window size: 800x800 title: snek game
    sf::RenderWindow window(sf::VideoMode(800, 800), "Snek Game");
    sf::Clock clock; //create clock
    float timer = 0.01f; //timer
    float delay = 0.1f; //delay betwen moves (how fast game is)

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();//close window
            }
            if (event.type == sf::Event::KeyPressed) {
                startGame = true;//start game on key press
                switch (event.key.code) { // move using the arrow keys
                    case sf::Keyboard::Up:
                        snake.setDirection(0, -1);
                        break;
                    case sf::Keyboard::Down:
                        snake.setDirection(0, 1);
                        break;
                    case sf::Keyboard::Left:
                        snake.setDirection(-1, 0);
                        break;
                    case sf::Keyboard::Right:
                        snake.setDirection(1, 0);
                        break;
                    default:
                        break;
                }
            }
        }

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        
        //update snake position if game has started and delay passed
        if (startGame && timer > delay) {
            timer = 0;
            // game over state
            if (!board.moveSnake(board, snake)) {
                window.close();
                ui.displayGameOver();
            }
        }
        
        //clear window
        window.clear(sf::Color::Black);

        //set black background creating rectangles 40x40
        sf::RectangleShape rectangle(sf::Vector2f(40, 40));

        ui.drawBoard(window, board, rectangle);

        //draw snake
        ui.drawSnake(window, snake, rectangle);
        
        //display score
        ui.displayScore(window, snake);

        window.display();
    }

    return 0;
}
