#include "laser.hpp"

Laser::Laser(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
    active = true;
}

void Laser::Draw()
{
    if (active)
        DrawRectangle(this->position.x, this->position.y, 4, 15, {255, 0, 0, 255});
}

void Laser::Update()
{
    this->position.y += speed;
    if (active)
    {
        if (position.y > GetScreenHeight() || position.y < 0)
        {
            active = false;
        }
    }
}