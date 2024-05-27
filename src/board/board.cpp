#include "board.h"
//#include <SFML/Graphics.hpp>
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

//remove food from specified cell on coordinations x and y
void Board::removeFood(int x, int y) {
    board_cells[y * dimensions[0] + x] = 0;
}
