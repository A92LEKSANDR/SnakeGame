#include "Snake.h"

Snake::Snake(int maxLength) : maxLength(maxLength), length(4), dir(0) {
    segment = new Segment[maxLength];
    for (int i = 0; i < length; ++i) {
        segment[i].x = 0;
        segment[i].y = 0;
    }
}

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
}

void Snake::Draw(sf::RenderWindow& window, sf::Sprite& sprite) {
    for (int i = 0; i < length; ++i) {
        sprite.setPosition(segment[i].x * consts::titleSize, segment[i].y * consts::titleSize);
        window.draw(sprite);
    }
}
