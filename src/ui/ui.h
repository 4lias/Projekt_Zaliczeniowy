#ifndef UI_H
#define UI_H

class UI {
public:
    void displayStartScreen();
    void displayGame();

    float easeExpIn(float time, float delay);
    float easeSinInOut(float time);
private:
    int screenDimensions[2] = {1920, 1080};
    float speed = 1.0f;
};

#endif // UI_H
