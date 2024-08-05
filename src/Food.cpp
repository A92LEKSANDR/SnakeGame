#include "Food.h"

Food::Food() {
    respawn();
}

void Food::respawn() {
    position.x = rand() % consts::countTileWeight;
    position.y = rand() % consts::countTileHeight;
}

void Food::draw(sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setPosition(position.x * consts::tileSize, position.y * consts::tileSize);
    window.draw(sprite);
}

sf::Vector2f Food::getPosition() const {
    return sf::Vector2f(position.x * consts::tileSize, position.y * consts::tileSize);
}

