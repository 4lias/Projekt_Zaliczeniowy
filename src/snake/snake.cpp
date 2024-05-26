#include "snake.h"

//constructor snake
Snake::Snake() {
    points = 0;
    level = 1;
    speed = 0.1f;
    length = 1;
    body.push_back({10, 10});// Initialize the snake's starting position
    //direction = {1, 0};
}
//get snake body as vector of coordinates
std::vector<std::pair<int, int>> Snake::getBody() {
    return body;
}
//get coordinates of snake's head
std::pair<int, int> Snake::getHead() {
    return body.front();
}
//set set direction of snake movement
void Snake::setDirection(int dx, int dy) {
    direction = {dx, dy};
}
//move snake in direction
void Snake::move() {
    auto head = body.front();//get head posision
    head.first += direction.first;//move head in x direction (horizontal)
    head.second += direction.second; //move head in y direction (vertical)
    body.insert(body.begin(), head);//insert new head position at beginning of body
    if (growNext) {
        growNext = false; //if snake should grow reset growNext
        points +=1;//increment points, if snake should grow means player scored point
    } else {
        body.pop_back(); //if not, remove last segment of snakes body
    }
}
//set flat to grow snake on next move
void Snake::grow() {
    growNext = true;
}

//check if snake has collided with itself
bool Snake::checkSelfCollision() {
    auto head = body.front();//get head position
    for (size_t i = 1; i < body.size(); ++i) { //iterate over body
        if (body[i] == head) { //check if any segment collides with head
            return true; //return true if collision detected
        }
    }
    return false;//no collision
}
//ad points to snake's score
void Snake::addPoints(int points) {
    score += points;
}

int Snake::getLength() {
    return length;
}

float Snake::getSpeed() const{
    return speed;
}

int Snake::getLevel() const{
    return level;
}

int Snake::getPoints() const{
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
