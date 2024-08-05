#pragma once
<<<<<<< HEAD
#include "SFMLHeaders.h"
#include "Snake.h"
#include "Food.h"
=======
#include <SFML/Graphics.hpp>
#include "Snake.h"
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
#include "constants.h"
#include <iostream>
#include <time.h>

<<<<<<< HEAD
enum class Direction { Right, Down, Left, Up };

class Game {
=======
class Game{
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
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
<<<<<<< HEAD
   // Food food;
public:
    Game();
    void run();
=======
public:
Game();
void run();
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
};
