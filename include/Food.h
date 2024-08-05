#pragma once
#include "SFMLHeaders.h"
#include "constants.h"

class Food {
private:
    sf::Vector2f position;
    sf::Texture foodTexture;
    sf::Sprite foodSprite;
    int windowWidth;
    int windowHeight;
    int tileSize;
public:
    Food(int windowWidth, int windowHeight, int tileSize);
    void respawn();
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;

};
