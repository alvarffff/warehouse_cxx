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

void Game::HandleInput()
{
    if (IsKeyDown(KEY_LEFT))
    {
        worker.MoveLeft();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        worker.MoveRight();
    }
    else if (IsKeyDown(KEY_UP))
    {
        worker.MoveUp();
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        worker.MoveDown();
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
