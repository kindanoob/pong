


#include "player.h"


Player::Player(const sf::Texture &texture, const std::string &name, 
	int x, int y, double dx, double dy, int w, int h, int row, int col)
    : Entity(texture, name, x, y, dx, dy, w, h, row, col) {
}
