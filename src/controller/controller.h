#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../board/board.h"
#include "../snake/snake.h"

class Controller {
public:
    bool generateBoard(Board& board);
    bool moveSnake(Board& board, Snake& snake);
    int launch();
private:
    Board board;
    Snake snake;
};

#endif // CONTROLLER_H
