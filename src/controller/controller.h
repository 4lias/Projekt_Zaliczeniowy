#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../board/board.h"
#include "../snake/snake.h"

class Controller {
public:
    bool generateBoard(Board& board); // Update signature to take reference
    bool moveSnake(Board& board, Snake& snake); // Update signature to take references
    int launch();
private:
    Board board;
    Snake snake;
};

#endif // CONTROLLER_H
