#include "Game.h"


Game::Game()
    :window(sf::VideoMode(consts::weight,consts::height), "Snake Game"){
    if(!background.loadFromFile("../resources/background.png")){
      
    }
        sprite.setTexture(background);
}

void Game::start(){
   while (window.isOpen()) {
       sf::Event event;
           while (window.pollEvent(event)) {
               if (event.type == sf::Event::Closed)
                   window.close();
           }

       window.clear(sf::Color::Black);
       // Drawing code here

       for(int i = 0; i < consts::n; ++i){
           for(int j = 0; j < consts::m; ++j){
                sprite.setPosition(i*consts::size,j*consts::size);
                window.draw(sprite);
           }
       }
       window.display();
   }
}
