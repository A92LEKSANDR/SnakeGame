#include "Snake.h"

<<<<<<< HEAD
Snake::Snake(int maxLength) : maxLength(maxLength), length(4), direction(0) {
    segment.resize(maxLength); // Инициализация вектора сегментов
=======
Snake::Snake(int maxLength) : maxLength(maxLength), length(4), dir(0) {
    segment = new Segment[maxLength];
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
    for (int i = 0; i < length; ++i) {
        segment[i].x = 0;
        segment[i].y = 0;
    }
}

<<<<<<< HEAD
void Snake::ChangeDirection(int newDirection) {
    direction = newDirection;
}

void Snake::Tick() {
    // Логика перемещения змейки
    // Обновляем позиции сегментов
    for (int i = length - 1; i > 0; --i) {
        segment[i] = segment[i - 1]; // Сдвиг сегментов
    }

    // Перемещение головы
    switch (direction) {
    case 0: segment[0].x++; break; // Вправо
    case 1: segment[0].y++; break; // Вниз
    case 2: segment[0].x--; break; // Влево
    case 3: segment[0].y--; break; // Вверх
    }
=======
void Snake::Tick() {
    for (int i = length; i > 0; --i) {
        segment[i].x = segment[i - 1].x;
        segment[i].y = segment[i - 1].y;
    }
    if (dir == 0) segment[0].y += 1;
    if (dir == 1) segment[0].x -= 1;
    if (dir == 2) segment[0].x += 1;
    if (dir == 3) segment[0].y -= 1;
}

void Snake::ChangeDirection(int newDirection) {
    dir = newDirection;
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
}

void Snake::Draw(sf::RenderWindow& window, sf::Sprite& sprite) {
    for (int i = 0; i < length; ++i) {
<<<<<<< HEAD
        sprite.setPosition(segment[i].x * consts::tileSize, segment[i].y * consts::tileSize);
        window.draw(sprite);
    }
}

sf::Vector2f Snake::getHeadPosition() const {
    return sf::Vector2f(segment[0].x * consts::tileSize, segment[0].y * consts::tileSize);
}

void Snake::grow() {
    if (length < maxLength) {
        segment[length] = segment[length - 1]; // Дублируем последний сегмент
        ++length; // Увеличиваем длину змейки
    }
}
=======
        sprite.setPosition(segment[i].x * consts::titleSize, segment[i].y * consts::titleSize);
        window.draw(sprite);
    }
}
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
