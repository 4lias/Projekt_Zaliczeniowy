#ifndef SNAKE_H
#define SNAKE_H

class Snake {
private:
    int points;
    int level;
    float speed;
    int length;

public:
    int getLength();
    float getSpeed();
    int getLevel();
    int getPoints();
    void setSpeed(float speed);
    void addLength(int length);
    void addLevel(int level);
    void addPoints(int points);
};

#endif // SNAKE_H
