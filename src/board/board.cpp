#include "board.h"
#include <SFML/Graphics.hpp>
#include "../snake/snake.h"

std::vector<int>& Board::getBoard_Cells() {
    return board_cells;
}

std::vector<int>& Board::getDimensions() {
    return dimensions;
}
void Board::placeFood() {

}

bool Board::checkCollision(int x, int y) {

    return false;
}

bool Board::generate(Board& board, Snake& snake) {
    board.getDimensions()[0] = 20;
    board.getDimensions()[1] = 20;
    board.getBoard_Cells().resize(20 * 20, 0);
    board.placeFood();
    return true;
}

bool Board::moveSnake(Board& board, Snake& snake) {
    snake.move();
    auto head = snake.getHead();
    if (board.checkCollision(head.first, head.second) || snake.checkSelfCollision()) {
        return false;
    }
    auto& cells = board.getBoard_Cells();
    if (cells[head.second * board.getDimensions()[0] + head.first] == 1) {
        snake.grow();
        snake.addPoints(10);
        board.placeFood();
    }
    return true;
}

int Board::launch() {
    Board board;
    Snake snake;

    if (!generate(board, snake)) {
        return -1;
    }

    sf::RenderWindow window(sf::VideoMode(800, 800), "Snek Game");
    sf::Clock clock;
    float timer = 0.0f;
    float delay = 0.1f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
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

        if (timer > delay) {
            timer = 0;
            if (!moveSnake(board, snake)) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        sf::RectangleShape rectangle(sf::Vector2f(40, 40));
        for (int i = 0; i < board.getDimensions()[1]; ++i) {
            for (int j = 0; j < board.getDimensions()[0]; ++j) {
                if (board.getBoard_Cells()[i * board.getDimensions()[0] + j] == 1) {
                    rectangle.setFillColor(sf::Color::Black);
                    rectangle.setPosition(j * 40, i * 40);
                    window.draw(rectangle);
                }
            }
        }

        for (auto segment : snake.getBody()) {
            rectangle.setFillColor(sf::Color::Green);
            rectangle.setPosition(segment.first * 40, segment.second * 40);
            window.draw(rectangle);
        }

        window.display();
    }

    return 0;
}
