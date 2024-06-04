#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../board/board.h"
#include "../snake/snake.h"

class Controller {
public:
    bool generateBoard(Board& board);
    bool moveSnake(Board& board, Snake& snake);
    /*
     Inicjalizuje komponenty gry (Board, Snake, UI).
    Wyświetla ekran startowy.
    Tworzy okno gry.
    Zarządza główną pętlą gry, obsługuje wydarzenia, aktualizuje stan gry i renderuje grę.
    Obsługa Zdarzeń

    Wykrywa zdarzenia zamknięcia okna.
    Rozpoczyna grę po naciśnięciu dowolnego klawisza.
    Zmienia kierunek węża na podstawie wejścia z klawiszy strzałek.

Pętla Gry

    Aktualizuje pozycję węża na podstawie zegara.
    Sprawdza warunki zakończenia gry.
    Renderuje komponenty gry (plansza, wąż, wynik) przy użyciu klasy UI.*/

    int launch();
private:
    Board board;
    Snake snake;
};

#endif // CONTROLLER_H
