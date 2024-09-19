#include <raylib.h>
#include "game.hpp"

int main()
{
    int window_width = 800;
    int window_height = 800;
    int frame_rate = 60;

    Color grey = {29, 29, 27, 255};
    Color red = {255, 0, 0, 255};

    InitWindow(window_width, window_height, "Warehouse");
    SetTargetFPS(frame_rate);

    Game game;
    game.LoadMap("map_w0.txt");
    // Checks if the windows close bottom is pressed
    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(grey);
        game.Update();
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}