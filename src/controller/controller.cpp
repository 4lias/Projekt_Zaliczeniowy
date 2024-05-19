#include "controller.h"
#include <SFML/Graphics.hpp>

int Controller::launch() {
    Board board;
    Snake snake;
    bool startGame = false;

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
            //close window if move fails
            if (!board.moveSnake(board, snake)) {
                window.close();
            }
        }
        //clear window
        window.clear(sf::Color::Black);
        //set black background creating rectangles 40x40
        sf::RectangleShape rectangle(sf::Vector2f(40, 40));
        for (int i = 0; i < board.getDimensions()[1]; ++i) {
            for (int j = 0; j < board.getDimensions()[0]; ++j) {
                if (board.getBoard_Cells()[i * board.getDimensions()[0] + j] == 1) {
                    rectangle.setFillColor(sf::Color::Red);
                    rectangle.setPosition(j * 40, i * 40);
                    window.draw(rectangle);
                }
            }
        }
        //draw green snake
        for (auto segment : snake.getBody()) {
            rectangle.setFillColor(sf::Color::Green);
            rectangle.setPosition(segment.first * 40, segment.second * 40);
            window.draw(rectangle);
        }

        window.display();
    }

    return 0;
}
