#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.h"

class Player: public Entity {
    Player(const sf::Texture &texture, const std::string &name, 
    	int x, int y, double dx, double dy, int w, int h, int row, int col);
    //void ProcessKeyboardInput();
};


#endif // PLAYER_H_
