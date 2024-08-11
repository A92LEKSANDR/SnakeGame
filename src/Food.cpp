#include "Food.h"

Food::Food(const Snake& snake) {
    respawn(snake);
}

void Food::respawn(const Snake& snake) {
     do {
        position.x = rand() % consts::countTileWeight;
        position.y = rand() % consts::countTileHeight;
    } while (snake.isOnSnake(position)); // Проверяем, что еда не на змейке
 }

void Food::Draw(sf::RenderWindow& window, sf::Sprite& sprite) {
    sprite.setPosition(position.x * consts::tileSize, position.y * consts::tileSize);
    window.draw(sprite);
}

sf::Vector2f Food::getPosition() const {
    return sf::Vector2f(position.x * consts::tileSize, position.y * consts::tileSize);
}

