#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include "../snake/snake.h"
#include "../board/board.h"

class UI {
public:
    bool displayStartScreen();
    void displayGame();
    void displayGameOver();

    void displayScore(sf::RenderWindow& window, Snake snake);
    void drawBoard(sf::RenderWindow &window, Board board, sf::RectangleShape rectangle);
    void drawSnake(sf::RenderWindow& window, Snake snake, sf::RectangleShape &rectangle);

    float easeExpIn(float, float);
    float easeSinInOut(float);
private:
    int screenDimensions[2] = {800, 800};
    float speed = 1.0f;

    sf::RenderWindow window;
};

#endif // UI_H
