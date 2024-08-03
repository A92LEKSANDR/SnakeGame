#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "constants.h"
#include <iostream>
#include <time.h>

class Game{
private:
    void ProcessEvents();
    void Update();
    void Render();
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Texture snakeTexture;
    sf::Sprite backgroundSprite;
    sf::Sprite snakeSprite;
    sf::Clock clock;
    float timer;
    float delay;
    Snake snake;
public:
Game();
void run();
};
