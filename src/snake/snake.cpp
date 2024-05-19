#include "snake.h"

Snake::Snake() {
    points = 0;
    level = 1;
    speed = 0.1f;
    length = 1;
    body.push_back({10, 10});
    direction = {1, 0};
}

std::vector<std::pair<int, int>> Snake::getBody() {
    return body;
}

std::pair<int, int> Snake::getHead() {
    return body.front();
}

void Snake::setDirection(int dx, int dy) {
    direction = {dx, dy};
}

void Snake::move() {
    auto head = body.front();
    head.first += direction.first;
    head.second += direction.second;
    body.insert(body.begin(), head);
    if (growNext) {
        growNext = false;
    } else {
        body.pop_back();
    }
}

void Snake::grow() {
    growNext = true;
}

bool Snake::checkSelfCollision() {
    auto head = body.front();
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i] == head) {
            return true;
        }
    }
    return false;
}

void Snake::addPoints(int points) {
    score += points;
}

int Snake::getLength() {
    return length;
}

float Snake::getSpeed() {
    return speed;
}

int Snake::getLevel() {
    return level;
}

int Snake::getPoints() {
    return points;
}

void Snake::setSpeed(float speed) {
    this->speed = speed;
}

void Snake::addLength(int length) {
    this->length += length;
}

void Snake::addLevel(int level) {
    this->level += level;
}
