#pragma once
#include "SFMLHeaders.h" 
#include <vector>
#include <iostream>
#include "constants.h"


class Snake {
public:
    enum class Direction{Right, Down, Left, Up};
   
    Snake(int maxLength);
    void Move(int dx, int dy);
    void ChangeDirection(Direction newDirection);
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
    Direction direction;
    int maxLength;
    int dir;
};

