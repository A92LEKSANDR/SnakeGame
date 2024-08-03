#include "Game.h"

Game::Game() : window(sf::VideoMode(consts::weightWindow,consts::heightWindow),"Snake Game", sf::Style::Close | sf::Style::Titlebar),
               snake(100),timer(0),delay(0.1f){

 if (!backgroundTexture.loadFromFile("../resources/background.png")) {
        std::cerr << "img for background loading error" << std::endl;
    }
    if (!snakeTexture.loadFromFile("../resources/sb.png")) {
        std::cerr << "img for snake loading error" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    snakeSprite.setTexture(snakeTexture);
    
    srand(time(0));
}   

void Game::run() {
    while (window.isOpen()) {
        ProcessEvents();
        Update();
        Render();
    }
}

void Game::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) { snake.ChangeDirection(1); }
            if (event.key.code == sf::Keyboard::Right) { snake.ChangeDirection(2); }
            if (event.key.code == sf::Keyboard::Up) { snake.ChangeDirection(3); }
            if (event.key.code == sf::Keyboard::Down) { snake.ChangeDirection(0); }
        }
    }
}

void Game::Update() {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    if (timer > delay) {
        timer = 0;
        snake.Tick();
    }
}

void Game::Render() {
    window.clear();
    for (int i = 0; i < consts::countTitleWeight; ++i) {
        for (int j = 0; j < consts::countTitleHeight; ++j) {
            backgroundSprite.setPosition(i * consts::titleSize, j * consts::titleSize);
            window.draw(backgroundSprite);
        }
    }
    snake.Draw(window, snakeSprite);
    window.display();
}
