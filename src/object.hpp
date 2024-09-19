#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"

class Object
{
public:
    Object(int x, int y);
    ~Object();
    void Draw();

private:
    Texture2D image;
    Vector2 position;
};

#endif