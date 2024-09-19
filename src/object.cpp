#include "object.hpp"
#include <cstdlib>

Object::Object(int x, int y)
{
    position.x = x * 80;
    position.y = y * 80;
}

Object::~Object()
{
}

void Object::Draw()
{
    DrawRectangle(position.x, position.y, 80, 80, {255, 0, 0, 255});
}
