#pragma once
#include "SFML.hpp"
#include "Snake.hpp"

namespace constants{
    const int weight = 800;
    const int height = 600;
}

class Game{
sf::RenderWindow window;
public:
    Game();
    void start();
};
