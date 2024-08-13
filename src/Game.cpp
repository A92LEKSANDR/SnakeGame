#include "Game.h"

Game::Game() : window(sf::VideoMode(consts::weightWindow, consts::heightWindow), "Snake Game"),
	      snake(100), timer(0), delay(0.1f),food(snake),state(GameState::Menu) {

    if (!backgroundTexture.loadFromFile("../resources/background.png")) {
        std::cerr << "img for background loading error" << "\n";
    }

    if (!snakeTexture.loadFromFile("../resources/sb.png")) {
        std::cerr << "img for snake loading error" << "\n";
    }

    if(!foodTexture.loadFromFile("../resources/food.png")){
        std::cerr << "img for fod loading error" << "\n";
    }

    backgroundSprite.setTexture(backgroundTexture);
    snakeSprite.setTexture(snakeTexture);
    foodSprite.setTexture(foodTexture);

    srand(static_cast<unsigned>(time(0)));
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

        switch (state) {
            case GameState::Menu:
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        state = GameState::Playing;
                    }
                }
                break;

            case GameState::Playing:
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                        case sf::Keyboard::Left:
                            snake.ChangeDirection(Snake::Direction::Left);
                            break;
                        case sf::Keyboard::Right:
                            snake.ChangeDirection(Snake::Direction::Right);
                            break;
                        case sf::Keyboard::Up:
                            snake.ChangeDirection(Snake::Direction::Up);
                            break;
                        case sf::Keyboard::Down:
                            snake.ChangeDirection(Snake::Direction::Down);
                            break;
                        case sf::Keyboard::Escape:
                            state = GameState::Menu;    
                        default:
                            break;
                    }
                }
                break;

            case GameState::GameOver:
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        RestartGame();
                        state = GameState::Playing;
                    }
                }
                break;

            default:
                break;
        }
    }
}


void Game::Update() {
    if(state != GameState::Playing){
        //dont update, when state Menu and GameOver
        return;
    }
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    if (timer > delay) {
        timer = 0;
        snake.Tick();

        if(snake.getHeadPosition() == food.getPosition()){
            snake.grow();
            food.respawn(snake);
        }
        if(snake.checkSelfCollision()){
            state = GameState::GameOver;
        }
    }
}

void Game::Render() {
    window.clear();
    if (state == GameState::Menu) {
        RenderMenu();
    } else if (state == GameState::Playing) {
        for (int i = 0; i < consts::countTileWeight; ++i) {
            for (int j = 0; j < consts::countTileHeight; ++j) {
                backgroundSprite.setPosition(i * consts::tileSize, j * consts::tileSize);
                window.draw(backgroundSprite);
            }
        }
        snake.Draw(window, snakeSprite);
        food.Draw(window, foodSprite); // Отрисовываем еду
    } else if (state == GameState::GameOver) {
        // Отображение экрана окончания игры
        // Например, текст "Game Over" и предложение нажать Enter для перезапуска
        sf::Font font;
        if (!font.loadFromFile("../resources/ArialRegular.ttf")) {
            std::cerr << "Font loading error" << std::endl;
        }
        sf::Text text("Game Over\nPress Enter to Restart", font, 25);
        text.setFillColor(sf::Color::Red);
        text.setPosition(consts::weightWindow / 4, consts::heightWindow / 3);
        window.draw(text);
    }
    window.display();
}

void Game::RenderMenu() {
    // Отображение главного меню
    // Например, текст "Press Enter to Start"
    sf::Font font;
    if (!font.loadFromFile("../resources/ArialRegular.ttf")) {
        std::cerr << "Font loading error" << std::endl;
    }

    for (int i = 0; i < consts::countTileWeight; ++i) {
        for (int j = 0; j < consts::countTileHeight; ++j) {
            backgroundSprite.setPosition(i * consts::tileSize, j * consts::tileSize);
            window.draw(backgroundSprite);
        }
    } 

    sf::Text text("Press Enter to Start", font, 25);
    text.setFillColor(sf::Color::White);
    text.setPosition(consts::weightWindow / 4, consts::heightWindow / 3);
    
       
    window.draw(text);
}

void Game::RestartGame() {
    snake = Snake(100); // Сбрасываем змейку
    food.respawn(snake); // Сбрасываем еду
    timer = 0; // Сбрасываем таймер
    std::cerr << "Game restarted!" << std::endl;
}
