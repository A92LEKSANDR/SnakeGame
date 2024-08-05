#pragma once
#include "SFMLHeaders.h" 
#include <vector>
#include <iostream>
#include "constants.h"

class Snake {
public:
    Snake(int maxLength);
    void Move(int dx, int dy);
    void ChangeDirection(int newDirection);
    void Tick();
    void Draw(sf::RenderWindow& window, sf::Sprite& sprite);
    sf::Vector2f getHeadPosition() const;
    void grow();


private:
    struct Segment {
        int x, y;
    };
    std::vector<Segment> segment;
    int length;
    int direction;
    int maxLength;
    int dir;
};

