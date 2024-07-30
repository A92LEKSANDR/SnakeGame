#pragma once
#include "Snake.h"
#include "constants.h" 

class Game{
sf::RenderWindow window;
sf::Texture background;
sf::Sprite sprite;
public:
    Game();
    void start();

};
