#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
public:
    Snake(int cellSize, int initialLength, int fieldWidth, int fieldHeight);

    void move();
    void setDirection(sf::Vector2i direction);
    void grow();
    bool checkSelfCollision() const;
    void draw(sf::RenderWindow& window) const;

private:
    std::vector<sf::Vector2i> segments;
    sf::Vector2i direction;
    int cellSize;
    int fieldWidth;
    int fieldHeight;

    void wrapAround();
};
