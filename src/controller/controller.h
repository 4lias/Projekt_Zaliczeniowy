#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../ui/ui.h"
#include "../board/board.h"
#include "../snake/snake.h"

class Controller {
private:
    UI ui;
    Board board;
    Snake snake;

public:
    bool generateBoard(Board board);
    bool moveSnake(Board board, Snake snake);
    //void test(UI ui);
    int launch();
};

#endif // CONTROLLER_H
