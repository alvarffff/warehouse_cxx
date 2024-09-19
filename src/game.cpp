#include "game.hpp"
#include <cstdio>
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Draw()
{
    worker.Draw();
    for (auto &object : objects)
    {

        object.Draw();
    }
}

void Game::Update()
{
    for (auto &object : objects)
    {
        if (CheckCollisionRecs(Rectangle{worker.position.x, worker.position.y, 60, 60}, Rectangle{object.position.x, object.position.y, 80, 80}))
        {
            switch (worker.direction)
            {
            case 0:
                break;
            case 1:
                worker.position.x = worker.position.x + 10;
                break;
            case 2:
                worker.position.x = worker.position.x - 10;
                break;
            case 3:
                worker.position.y = worker.position.y + 10;
                break;
            case 4:
                worker.position.y = worker.position.y - 10;
                break;

            default:
                break;
            }
        }
    }
}

void Game::HandleInput()
{
    if (IsKeyDown(KEY_LEFT))
    {
        worker.direction = 1;
        worker.MoveLeft();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        worker.direction = 2;
        worker.MoveRight();
    }
    else if (IsKeyDown(KEY_UP))
    {
        worker.direction = 3;
        worker.MoveUp();
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        worker.direction = 4;
        worker.MoveDown();
    }
    else
    {
        worker.direction = 0;
    }
}

void Game::LoadMap(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
    }
    // read one character at a time and
    // display it to the output
    char ch;
    int count_x = 0;
    int count_y = 0;
    std::cout << "Following map loaded: \n";
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            count_y++;
            count_x = 0;
        }
        else
        {
            if (ch != '0' && ch != '\r')
            {

                if (ch == '1')
                {
                    objects.emplace_back(count_x, count_y);
                }
                if (ch == '4')
                {
                    worker.SetPosition(count_x, count_y);
                }
            }
            count_x++;
        }

        putchar(ch);
    }
}
