#include "Snake.h"

Snake::Snake(int maxLength) : maxLength(maxLength), length(4), direction(0) {
    segment.resize(maxLength); // Инициализация вектора сегментов
    for (int i = 0; i < length; ++i) {
        segment[i].x = 0;
        segment[i].y = 0;
    }
}

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
}

void Snake::Draw(sf::RenderWindow& window, sf::Sprite& sprite) {
    for (int i = 0; i < length; ++i) {
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