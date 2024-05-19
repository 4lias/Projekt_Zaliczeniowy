#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Snake;

class Board {
public:
    std::vector<int>& getBoard_Cells();
    std::vector<int>& getDimensions();
    void placeFood();
    bool checkCollision(int x, int y);
    bool generate(Board& board, Snake& snake);
    bool moveSnake(Board& board, Snake& snake);
    int launch();
    void removeFood(int x, int y);
private:
    std::vector<int> board_cells;
    std::vector<int> dimensions = {0, 0};
};

#endif // BOARD_H
