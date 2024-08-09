#pragma once
#include "SFMLHeaders.h"
#include "Snake.h"
#include "Food.h"
#include "constants.h"
#include <iostream>
#include <time.h>

enum class GameState{Menu,Playing, GameOver};

class Game{
private:
    void ProcessEvents();
    void Update();
    void Render();
    void RenderMenu();
    void RestartGame();
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
    GameState state;
public:
    Game();
    void run();
};
