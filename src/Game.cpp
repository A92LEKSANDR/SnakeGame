#include "Game.h"

<<<<<<< HEAD
Game::Game() : window(sf::VideoMode(consts::weightWindow, consts::heightWindow), "Snake Game", sf::Style::Close | sf::Style::Titlebar),
snake(100), timer(0), delay(0.1f) {

    if (!backgroundTexture.loadFromFile("resources/background.png")) {
        std::cerr << "img for background loading error" << std::endl;
    }
    if (!snakeTexture.loadFromFile("resources/sb.png")) {
=======
Game::Game() : window(sf::VideoMode(consts::weightWindow,consts::heightWindow),"Snake Game", sf::Style::Close | sf::Style::Titlebar),
               snake(100),timer(0),delay(0.1f){

 if (!backgroundTexture.loadFromFile("../resources/background.png")) {
        std::cerr << "img for background loading error" << std::endl;
    }
    if (!snakeTexture.loadFromFile("../resources/sb.png")) {
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
        std::cerr << "img for snake loading error" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    snakeSprite.setTexture(snakeTexture);
<<<<<<< HEAD

    srand(static_cast<unsigned>(time(0)));
}
=======
    
    srand(time(0));
}   
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08

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
<<<<<<< HEAD
            if (event.key.code == sf::Keyboard::Left) { 
                snake.ChangeDirection(static_cast<int>(Direction::Left)); 
            } // Влево
            if (event.key.code == sf::Keyboard::Right) { 
                snake.ChangeDirection(static_cast<int>(Direction::Right)); 
            } // Вправо
            if (event.key.code == sf::Keyboard::Up) { 
               snake.ChangeDirection(static_cast<int>(Direction::Up));
            } // Вверх
            if (event.key.code == sf::Keyboard::Down) {
                snake.ChangeDirection(static_cast<int>(Direction::Down));
            } // Вниз
=======
            if (event.key.code == sf::Keyboard::Left) { snake.ChangeDirection(1); }
            if (event.key.code == sf::Keyboard::Right) { snake.ChangeDirection(2); }
            if (event.key.code == sf::Keyboard::Up) { snake.ChangeDirection(3); }
            if (event.key.code == sf::Keyboard::Down) { snake.ChangeDirection(0); }
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
        }
    }
}

void Game::Update() {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    if (timer > delay) {
        timer = 0;
<<<<<<< HEAD
        snake.Tick(); // Обновляем положение змейки
=======
        snake.Tick();
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
    }
}

void Game::Render() {
    window.clear();
<<<<<<< HEAD
    for (int i = 0; i < consts::countTileWeight; ++i) {
        for (int j = 0; j < consts::countTileHeight; ++j) {
            backgroundSprite.setPosition(i * consts::tileSize, j * consts::tileSize);
=======
    for (int i = 0; i < consts::countTitleWeight; ++i) {
        for (int j = 0; j < consts::countTitleHeight; ++j) {
            backgroundSprite.setPosition(i * consts::titleSize, j * consts::titleSize);
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
            window.draw(backgroundSprite);
        }
    }
    snake.Draw(window, snakeSprite);
    window.display();
}
