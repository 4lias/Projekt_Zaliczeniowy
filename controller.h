#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ui.h"
#include "board.h"
#include "snake.h"

class Controller {
private:
    ui ui;
    Board board;
    Snake snake;

public:
    bool generateBoard(Board board);
    bool moveSnake(Board board, Snake snake);
    bool launch();
};

#endif // CONTROLLER_H
