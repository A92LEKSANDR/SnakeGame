#pragma once
#include "SFMLHeaders.h"
#include "Snake.h"
#include "Food.h"
#include "constants.h"
#include <iostream>
#include <time.h>

enum class Direction { Right, Down, Left, Up };

class Game{
private:
    void ProcessEvents();
    void Update();
    void Render();
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Texture snakeTexture;
    sf::Texture foodTexture;
    sf::Sprite backgroundSprite;
    sf::Sprite snakeSprite;
    sf::Sprite foodSprite;
    sf::Clock clock;
    float timer;
    float delay;
    Snake snake;
    Food food;
public:
    Game();
    void run();
};
