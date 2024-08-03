#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

class Snake {
private:
    struct Segment {
        int x, y;
    };
    int maxLength;
    int length;
    int dir; // direction
    Segment* segment;
public:
    Snake(int maxLength);
    void Tick();
    void ChangeDirection(int newDirection);
    void Draw(sf::RenderWindow& window, sf::Sprite& sprite);
};

