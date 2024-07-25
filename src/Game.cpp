#include "Game.hpp"


Game::Game():window(sf::VideoMode(constants::weight,constants::height), "Snake Game"){}

void Game::start(){
   while (window.isOpen()) {
       sf::Event event;
           while (window.pollEvent(event)) {
               if (event.type == sf::Event::Closed)
                   window.close();
           }

       window.clear(sf::Color::White);
       // Drawing code here
       window.display();
   }
}
