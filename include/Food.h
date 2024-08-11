#pragma once
#include "SFMLHeaders.h"
#include "constants.h"
#include "Snake.h"

class Food {
private:
    sf::Vector2f position;
public:
    Food(const Snake& snake);
    void respawn(const Snake& snake);
    void Draw(sf::RenderWindow& window,sf::Sprite& sprite);
    sf::Vector2f getPosition() const;
};
