#ifndef WORKER_H
#define WORKER_H

#include "raylib.h"

class Worker
{
public:
    Worker();
    ~Worker();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    void SetPosition(int x, int y);
    Vector2 position;
    int direction; // 0 NO movement, 1left, 2 right, 3 up, 4 down
private:
    Texture2D image;

    int velocity;
};

#endif