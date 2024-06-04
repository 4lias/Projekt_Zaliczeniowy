#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Snake;

/*
 @brief Klasa Board zarządza planszą gry, w tym położeniem jedzenia, przeszkód oraz sprawdzaniem kolizji.
 */
class Board {
public:
    /*
      @brief Zwraca komórki planszy.
      @return Wektor komórek planszy.
     */
    std::vector<int>& getBoard_Cells();

    /*
     @brief Zwraca wymiary planszy.
      @return Wektor wymiarów planszy.
     */
    std::vector<int>& getDimensions();

    /*
      @brief Umieszcza jedzenie na planszy.
     */
    void placeFood();

    /*
      @brief Umieszcza przeszkody na planszy.
     */
    void placeObsticles();

    /*
      @brief Sprawdza kolizję w danym punkcie.
      @param x Współrzędna X punktu.
      @param y Współrzędna Y punktu.
      @return Zwraca true, jeśli w punkcie (x, y) występuje kolizja, w przeciwnym razie false.
     */
    bool checkCollision(int x, int y);

    /*
      @brief Generuje nową planszę i inicjalizuje węża.
      @param board Obiekt planszy do wygenerowania.
      @param snake Obiekt węża do inicjalizacji.
      @return Zwraca true, jeśli plansza została pomyślnie wygenerowana, w przeciwnym razie false.
     */
    bool generate(Board& board, Snake& snake);

    /*
      @brief Przesuwa węża na planszy.
      @param board Obiekt planszy, na której wąż się porusza.
      @param snake Obiekt węża do przesunięcia.
      @return Zwraca true, jeśli wąż został pomyślnie przesunięty, w przeciwnym razie false.
     */
    bool moveSnake(Board& board, Snake& snake);

    /*
      @brief Usuwa jedzenie z planszy w danym punkcie.
      @param x Współrzędna X punktu.
      @param y Współrzędna Y punktu.
     */
    void removeFood(int x, int y);

private:
    std::vector<int> board_cells; /*< Wektor przechowujący komórki planszy. */
    std::vector<int> dimensions = {0, 0}; /*< Wektor przechowujący wymiary planszy. */
};

#endif // BOARD_H
