#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include "../snake/snake.h"
#include "../board/board.h"

/*
  @brief Klasa UI obsługuje interfejs graficzny, w tym wyświetlanie ekranu startowego, ekranu końca gry oraz rysowanie komponentów gry.
 */
class UI {
public:
    /*
     *@brief Wyświetla ekran startowy z animacjami.

     Czeka na dane wejściowe od użytkownika, aby rozpocząć grę.
     @return Zwraca true, jeśli ekran startowy został wyświetlony pomyślnie, w przeciwnym razie false.
     */
    bool displayStartScreen();
    void displayGame();

    /*
      @brief Wyświetla ekran końca gry.

      @param points Liczba punktów uzyskanych przez gracza.
     */
    void displayGameOver(int points);

    /*
     @brief Wyświetla bieżący wynik.

     @param window Okno, w którym wyświetlany jest wynik.
     @param snake Obiekt węża zawierający aktualny wynik.
     */
    void displayScore(sf::RenderWindow& window, Snake snake);

    /*
     @brief Rysuje planszę gry.
     @param window Okno, w którym rysowana jest plansza.
      @param board Obiekt planszy do narysowania.
     @param rectangle Kształt prostokąta używany do rysowania.
     */
    void drawBoard(sf::RenderWindow &window, Board board, sf::RectangleShape rectangle);

    /*
      @brief Rysuje węża.

      @param window Okno, w którym rysowany jest wąż.
      @param snake Obiekt węża do narysowania.
      @param rectangle Kształt prostokąta używany do rysowania.
     */
    void drawSnake(sf::RenderWindow& window, Snake snake, sf::RectangleShape &rectangle);

    /*
      @brief Funkcja easingowa wykorzystywana do animacji.

      @param time Czas animacji.
      @param delay Opóźnienie animacji.
      @return Zmodyfikowany czas po zastosowaniu funkcji easingowej.
     */
    float easeExpIn(float time, float delay = 0);

    /*
      @brief Funkcja easingowa wykorzystująca sinusoidę do animacji.

      @param time Czas animacji.
      @return Zmodyfikowany czas po zastosowaniu funkcji easingowej.
     */
    float easeSinInOut(float time);

private:
    int screenDimensions[2] = {800, 800}; /*< Wymiary okna gry. */
    float speed = 1.0f; /*< Prędkość animacji. */

    sf::RenderWindow window; /*< Okno gry. */
};

#endif // UI_H
