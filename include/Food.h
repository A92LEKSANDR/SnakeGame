#pragma once
#include "SFMLHeaders.h"
#include "constants.h"

class Food {
private:
    sf::Vector2f position;
public:
    Food();
    void respawn();
    void Draw(sf::RenderWindow& window,sf::Sprite& sprite);
    sf::Vector2f getPosition() const;
};
