#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>
/**
 * Klasa Snake reprezentuje węża i zarządza jego ruchem, wzrostem i wykrywaniem kolizji.
 */
class Snake {
private:
    int points;/**< Aktualna liczba punktów węża. */
    int level;/**< Aktualny poziom węża. - nie używane*/
    float speed; /**< Prędkość poruszania się węża. */
    int length;/**< Długość węża. */
    std::vector<std::pair<int, int>> body; /**< Współrzędne segmentów ciała węża. */
    std::pair<int, int> direction; /**< Aktualny kierunek ruchu węża. */
    bool growNext = false; /**< Flaga określająca, czy wąż ma urosnąć przy następnym ruchu. */
    int score; /**< Wynik gry. */

public:
    /**
  * Konstruktor inicjalizuje węża.
  */
    Snake();
    int getLength();
    float getSpeed() const;
    int getLevel() const;
    /*
      Zwraca aktualną liczbę punktów węża.
      Liczba punktów węża.
     */
    int getPoints() const;
    void setSpeed(float speed);
    void addLength(int length);
    void addLevel(int level);
    /*
      Dodaje punkty do wyniku węża.
      points Punkty do dodania.
     */
    void addPoints(int points);
    /*
     @brief Zwraca współrzędne ciała węża.
     @return Wektor współrzędnych segmentów ciała węża.
    */
    std::vector<std::pair<int, int>> getBody();
    /*
      @brief Zwraca współrzędne głowy węża.
      @return Współrzędne głowy węża.
     */
    std::pair<int, int> getHead();
    /*
     @brief Ustawia kierunek ruchu węża.
     @param dx Zmiana współrzędnej X.
     @param dy Zmiana współrzędnej Y.
    */
    void setDirection(int dx, int dy);
    /*
      @brief Porusza węża w bieżącym kierunku.
     */
    void move();
    /*
      @brief Ustawia węża do wzrostu przy następnym ruchu.
     */
    void grow();
    /*
     @brief Sprawdza, czy wąż zderzył się sam ze sobą.
     @return True, jeśli wąż zderzył się sam ze sobą, w przeciwnym razie false.
    */
    bool checkSelfCollision();
};

#endif // SNAKE_H
