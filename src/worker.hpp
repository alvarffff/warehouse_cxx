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

private:
    Texture2D image;

    int velocity;
};

#endif