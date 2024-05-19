#include "board.h"
#include <SFML/Graphics.hpp>
#include "../snake/snake.h"
#include <ctime>
#include <cstdlib>

// return vector cells of the board.
std::vector<int>& Board::getBoard_Cells() {
    return board_cells;
}
// return vector dimensions of the board
std::vector<int>& Board::getDimensions() {
    return dimensions;
}

//place food randomly on board
void Board::placeFood() {
    srand(time(0)); //random number generator
    int x, y;
    do {
        x = rand() % dimensions[0]; //random x coordinate
        y = rand() % dimensions[1]; //random y coordinate
    } while (board_cells[y * dimensions[0] + x] != 0); //ensure cell is empty
    board_cells[y * dimensions[0] + x] = 1; //place food
}

//chceck if position x,y is off board
bool Board::checkCollision(int x, int y) {
    if (x < 0 || x >= dimensions[0] || y < 0 || y >= dimensions[1]) {
        return true;
    }
    return false;
}

//initialaze board and snake
bool Board::generate(Board& board, Snake& snake) {
    board.getDimensions()[0] = 20; //set board width
    board.getDimensions()[1] = 20; //set board height
    board.getBoard_Cells().resize(20 * 20, 0); //create board cells with zeros
    board.placeFood(); //place food
    return true;
}

//move snake on board
bool Board::moveSnake(Board& board, Snake& snake) {
    snake.move(); //move saneke
    auto head = snake.getHead(); //get new head position
    if (board.checkCollision(head.first, head.second) || snake.checkSelfCollision()) {
        return false; //chceck for collision
    }
    auto& cells = board.getBoard_Cells();
    //chceck if snake eat food
    if (cells[head.second * board.getDimensions()[0] + head.first] == 1) {
        snake.grow(); //geow snake
        snake.addPoints(10); //add points
        board.removeFood(head.first, head.second); //remove eaten food
        board.placeFood(); //place food
    }
    return true;
}
//launch game board
int Board::launch() {
    Board board;
    Snake snake;

    if (!generate(board, snake)) {
        return -1;
    }
    //create game window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Snek Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); //chceck if window were closed
            }
            if (event.type == sf::Event::KeyPressed) { //controls
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

        window.clear(sf::Color::Black); //clear window and make it black
        sf::RectangleShape rectangle(sf::Vector2f(40, 40)); //create rectangle size 40x40
        for (int i = 0; i < board.getDimensions()[1]; ++i) {
            for (int j = 0; j < board.getDimensions()[0]; ++j) {
                if (board.getBoard_Cells()[i * board.getDimensions()[0] + j] == 1) {
                    rectangle.setFillColor(sf::Color::Black);
                    rectangle.setPosition(j * 40, i * 40);
                    window.draw(rectangle);
                }
            }
        }
        //draw snake and make it green
        for (auto segment : snake.getBody()) {
            rectangle.setFillColor(sf::Color::Green);
            rectangle.setPosition(segment.first * 40, segment.second * 40);
            window.draw(rectangle);
        }

        window.display();
    }

    return 0;
}

//remove food from specified cell on coordinations x and y
void Board::removeFood(int x, int y) {
    board_cells[y * dimensions[0] + x] = 0;
}
