#include "Snake.h"
#include "Game.h"

Snake::Snake(int maxLength) : maxLength(maxLength), length(4), direction(Direction::Right) {
    segment.resize(maxLength);
    for (int i = 0; i < length; ++i) {
        segment[i].x = 0;
        segment[i].y = 0;
    }
}

void Snake::ChangeDirection(Direction newDirection) {
    direction = newDirection;
}

void Snake::Tick() {
    for (int i = length - 1; i > 0; --i) {
        segment[i] = segment[i - 1];
    }

    switch (direction) {
    case 0: segment[0].x++; break; // ¬право
    case 1: segment[0].y++; break; // ¬низ
    case 2: segment[0].x--; break; // ¬лево
    case 3: segment[0].y--; break; // ¬верх
    }

    segment[0].x = (segment[0].x + consts::countTileWeight) % consts::countTileWeight;
    segment[0].y = (segment[0].y + consts::countTileHeight) % consts::countTileHeight;
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
        segment[length] = segment[length - 1];
        ++length;
    }
}
