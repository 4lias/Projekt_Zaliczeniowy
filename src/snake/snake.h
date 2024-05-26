#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

class Snake {
private:
    int points;
    int level;
    float speed;
    int length;
    std::vector<std::pair<int, int>> body;
    std::pair<int, int> direction;
    bool growNext = false;
    int score;

public:
    Snake();
    int getLength();
    float getSpeed() const;
    int getLevel() const;
    int getPoints() const;
    void setSpeed(float speed);
    void addLength(int length);
    void addLevel(int level);
    void addPoints(int points);
    std::vector<std::pair<int, int>> getBody();
    std::pair<int, int> getHead();
    void setDirection(int dx, int dy);
    void move();
    void grow();
    bool checkSelfCollision();
};

#endif // SNAKE_H
