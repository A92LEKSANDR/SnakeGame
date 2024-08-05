#pragma once
#include <SFML/Graphics.hpp>
<<<<<<< HEAD
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

=======
#include "constants.h"

class Snake {
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
private:
    struct Segment {
        int x, y;
    };
<<<<<<< HEAD

    std::vector<Segment> segment;
    int maxLength;
    int length;
    int direction;
=======
    int maxLength;
    int length;
    int dir; // direction
    Segment* segment;
public:
    Snake(int maxLength);
    void Tick();
    void ChangeDirection(int newDirection);
    void Draw(sf::RenderWindow& window, sf::Sprite& sprite);
>>>>>>> 25a33a6d0faaef2a9f064c1ba4c436c4b84bec08
};

