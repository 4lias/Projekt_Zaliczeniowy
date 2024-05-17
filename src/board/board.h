#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Snake; // Forward declaration

class Board {
public:
    std::vector<int>& getBoard_Cells(); // Return a reference
    std::vector<int>& getDimensions(); // Return a reference
    std::string& getBoard_Cells_Type(); // Return a reference
    void placeFood(); // Method to place food on the board
    bool checkCollision(int x, int y); // Method to check for collisions
    bool generate(Board& board, Snake& snake); // Method to generate the board
    bool moveSnake(Board& board, Snake& snake); // Method to move the snake on the board
    int launch(); // Method to launch the game

private:
    std::vector<int> board_cells;
    std::vector<int> dimensions = {0, 0}; // Initialize dimensions
    std::string board_type;
};

#endif // BOARD_H
