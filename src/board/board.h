#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Board {
private:
    int dimensions[2];
    std::vector<int> board_cells;
    std::string board_cells_type;

public:
    int* getDimensions();
    std::vector<int> getBoard_Cells();
    std::string getBoard_Cells_Type();
};

#endif // BOARD_H //chuj
