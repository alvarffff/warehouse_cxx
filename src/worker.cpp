#include "worker.hpp"

Worker::Worker()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x = 10;
    position.y = 10;
    velocity = 10;
}

Worker::~Worker()
{
    UnloadTexture(image);
}

void Worker::Draw()
{
    // DrawTextureV(image, position, WHITE);
    DrawRectangle(position.x, position.y, 60, 60, {255, 255, 255, 255});
}

void Worker::MoveLeft()
{
    position.x -= this->velocity;
    if (position.x < 0)
        position.x = 0;
}

void Worker::MoveRight()
{
    position.x += this->velocity;
    if (position.x > GetScreenWidth() - image.width)
        position.x = GetScreenWidth() - image.width;
}

void Worker::MoveUp()
{
    position.y -= this->velocity;
    if (position.y < 0)
        position.y = 0;
}

void Worker::MoveDown()
{
    position.y += this->velocity;
    if (position.y > GetScreenHeight() - image.height)
        position.y = GetScreenHeight() - image.height;
}

void Worker::SetPosition(int x, int y)
{
    position.x = x * 80;
    position.y = y * 80;
}
