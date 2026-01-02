#include "Game.h"
//#include <cstdio>
#include <stdexcept>

Game::Game() 
    : window(sf::VideoMode(sf::Vector2u(consts::weightWindow, consts::heightWindow)),"Snake Game"),
     snake(100),
     timer(0),
     delay(0.1f),
     food(snake),
     state(GameState::Menu),
     sound(buffer)
    {
   
   // Загрузка текстур
    if (!backgroundTexture.loadFromFile("../../resources/background.png")) {
        std::cerr << "Failed to load background texture\n";
    }
    if (!snakeTexture.loadFromFile("../../resources/sb.png")) {
        std::cerr << "Failed to load snake texture\n";
    }
    if (!foodTexture.loadFromFile("../../resources/food.png")) {
        std::cerr << "Failed to load food texture\n";
    }
    
    // Инициализация спрайтов
    backgroundSprite = std::make_unique<sf::Sprite>(backgroundTexture);
    snakeSprite = std::make_unique<sf::Sprite>(snakeTexture);
    foodSprite = std::make_unique<sf::Sprite>(foodTexture);


   if(!buffer.loadFromFile("../../resources/eat.wav")){
    throw std::runtime_error("Failed to load sound buffer");
   }        
   if(!music.openFromFile("../../resources/main.ogg")){
    throw std::runtime_error("Failed to load music");
   }
    sound.setBuffer(buffer);
    music.setLooping(true);
    music.setVolume(50);
    music.play();

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
    while (auto event = window.pollEvent()) {
        if(!event) continue;

        if (event->is<sf::Event::Closed>()) {
            window.close();
            continue;
        }

        // Обработка общих событий (если есть)
        if (handleCommonEvents(*event)) {
            continue;
        }

        // Обработка событий по состояниям
        switch (state) {
        case GameState::Menu: handleMenuEvent(*event); break;
        case GameState::Playing: handlePlayingEvent(*event); break;
        case GameState::GameOver: handleGameOverEvent(*event); break;
        default: break;
        }
    }
}

void Game::handleMenuEvent(const sf::Event& event) {
    if (!event.is<sf::Event::KeyPressed>()) return;

    const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
    if (keyEvent && keyEvent->scancode == sf::Keyboard::Scan::Enter) {
        state = GameState::Playing;
    }
}

void Game::handlePlayingEvent(const sf::Event& event) {
    if (!event.is<sf::Event::KeyPressed>()) return;

    const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
    if (!keyEvent) return;

    processPlayerInput(keyEvent->scancode);
}

void Game::processPlayerInput(sf::Keyboard::Scancode scancode) {
    static const std::unordered_map<sf::Keyboard::Scancode, Snake::Direction> keyToDirection = {
                                                                                                {sf::Keyboard::Scan::Left, Snake::Direction::Left},
                                                                                                {sf::Keyboard::Scan::Right, Snake::Direction::Right},
                                                                                                {sf::Keyboard::Scan::Up, Snake::Direction::Up},
                                                                                                {sf::Keyboard::Scan::Down, Snake::Direction::Down},
                                                                                                };

    // Специальные клавиши
    if (scancode == sf::Keyboard::Scan::Escape) {
        state = GameState::Menu;
        return;
    }

    // Проверяем, является ли клавиша направлением
    auto it = keyToDirection.find(scancode);
    if (it == keyToDirection.end()) return;

    Snake::Direction currentDirection = snake.getDirection();
    Snake::Direction newDirection = it->second;

    // Проверка противоположного направления
    if (isOppositeDirection(currentDirection, newDirection)) {
        return;
    }

    if (newDirection != currentDirection) {
        snake.ChangeDirection(newDirection);
    }
}

bool Game::isOppositeDirection(Snake::Direction dir1, Snake::Direction dir2) {
    return (dir1 == Snake::Direction::Left && dir2 == Snake::Direction::Right) ||
           (dir1 == Snake::Direction::Right && dir2 == Snake::Direction::Left) ||
           (dir1 == Snake::Direction::Up && dir2 == Snake::Direction::Down) ||
           (dir1 == Snake::Direction::Down && dir2 == Snake::Direction::Up);
}

bool Game::handleCommonEvents(const sf::Event& event) {
    // Здесь можно обрабатывать события, которые нужны во всех состояниях
    // Например: пауза, скриншоты, глобальные горячие клавиши

    // Пример: обработка клавиши P для паузы
    if (event.is<sf::Event::KeyPressed>()) {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
        if (keyEvent && keyEvent->scancode == sf::Keyboard::Scan::P) {
            // Переключение паузы
            if (state == GameState::Playing) {
                state = GameState::Menu; // или создайте отдельное состояние Paused
                music.pause();
            } else if (state == GameState::Menu) {
                state = GameState::Playing;
                music.play();
            }
            return true; // Событие обработано
        }
    }

    return false; // Событие не обработано как общее
}

void Game::handleGameOverEvent(const sf::Event& event) {
    if (!event.is<sf::Event::KeyPressed>()) return;

    const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
    if (!keyEvent) return;

    // Обработка клавиш в состоянии GameOver
    switch (keyEvent->scancode) {
    case sf::Keyboard::Scan::Enter:
        RestartGame();
        state = GameState::Playing;
        break;

    case sf::Keyboard::Scan::Escape:
        state = GameState::Menu;
        break;

    default:
        break;
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
            sound.play();
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
                backgroundSprite->setPosition(sf::Vector2f(i *static_cast<float>(consts::tileSize), static_cast<float>(j * consts::tileSize)));
                window.draw(*backgroundSprite);
            }
        }
        snake.Draw(window, *snakeSprite);
        food.Draw(window, *foodSprite); // Отрисовываем еду
    } else if (state == GameState::GameOver) {
        // Отображение экрана окончания игры
        // Например, текст "Game Over" и предложение нажать Enter для перезапуска
        sf::Font font;
        if (!font.openFromFile("../../resources/ArialRegular.ttf")) {
            throw std::runtime_error("Failed to load font");
        }
        sf::Text text(font);
       // text.setFont(font);
        text.setString("Game Over\nPress Enter to Restart");
        text.setCharacterSize(25);
        text.setFillColor(sf::Color::Red);
        text.setPosition(sf::Vector2f(
             consts::weightWindow / 4,
             consts::heightWindow / 3
        ));
        window.draw(text);
    }
    window.display();
}

void Game::RenderMenu() {
    // Отображение главного меню
    // Например, текст "Press Enter to Start"
    music.pause();
    sf::Font font;
    if (!font.openFromFile("../../resources/ArialRegular.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    for (int i = 0; i < consts::countTileWeight; ++i) {
        for (int j = 0; j < consts::countTileHeight; ++j) {
            backgroundSprite->setPosition(
                    sf::Vector2f(i * static_cast<float>(consts::tileSize),
                                 j * static_cast<float>(consts::tileSize))
                    );
           window.draw(*backgroundSprite);
        }
    }

    sf::Text text(font);
    text.setFont(font);
    text.setString("Press Enter to Start");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(
        consts::weightWindow / 4,
        consts::heightWindow / 3
    ));       
    window.draw(text);
}

void Game::RestartGame() {
    snake = Snake(100); // Сбрасываем змейку
    food.respawn(snake); // Сбрасываем еду
    timer = 0; // Сбрасываем таймер
    std::cerr << "Game restarted!" << std::endl;
}
