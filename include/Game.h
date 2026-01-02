#pragma once
#include "SFMLHeaders.h"
#include "Snake.h"
#include "Food.h"
#include "constants.h"
#include <iostream>
#include <time.h>
#include "memory"

enum class GameState{Menu,Playing, GameOver};

class Game{
private:
    void ProcessEvents();
    void Update();
    void Render();
    void RenderMenu();
    void RestartGame();
    
    void handleMenuEvent(const sf::Event& event);
    void handlePlayingEvent(const sf::Event& event);
    void processPlayerInput(sf::Keyboard::Scancode scancode);
    bool isOppositeDirection(Snake::Direction dir1, Snake::Direction dir2);
    void handleGameOverEvent(const sf::Event& event);
    bool handleCommonEvents(const sf::Event& event);

    sf::RenderWindow window;

    sf::Texture backgroundTexture;
    sf::Texture snakeTexture;
    sf::Texture foodTexture;
    
    std::unique_ptr<sf::Sprite> backgroundSprite;
    std::unique_ptr<sf::Sprite> snakeSprite;
    std::unique_ptr<sf::Sprite> foodSprite;

    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Music music;

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
