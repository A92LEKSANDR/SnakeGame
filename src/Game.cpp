#include "Game.h"


Game::Game()
    :window(sf::VideoMode(CONST::weight,CONST::height), "Snake Game"){
    if(!background.loadFromFile("resources/background.png")){
        
    }
    else{
        sprite.setTexture(background);
    }
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

       for(int i = 0; i < CONST::n; ++i){
           for(int j = 0; j < CONST::m; ++j){
                sprite.setPosition(i*CONST::size,j*CONST::size);
                window.draw(sprite);
           }
       }
       window.display();
   }
}
