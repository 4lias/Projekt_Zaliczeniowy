#ifndef UI_H
#define UI_H

class UI {
public:
    void displayGame();
    float expOutEase(float t, float b = 0, float c = 1, float d = 1);
    float sinInOutEase(float t);
private:
    int screenDimensions[2] = {800, 800};
    float speed = 1.0f;
};

#endif // UI_H
