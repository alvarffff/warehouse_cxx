#ifndef GAME_H
#define GAME_H

#include "worker.hpp"
#include "object.hpp"
#include <vector>

using namespace std;

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    void LoadMap(char *pathname);

private:
    Worker worker;
    int num_objects;
    vector<Object> objects;
};

#endif