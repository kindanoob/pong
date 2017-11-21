#include "entity.h"


Entity::Entity(const sf::Texture &texture, const std::string &name, 
    int x, int y, double dx, double dy, int w, int h, int row, int col):
    name_(name), h_(h), w_(w), x_(x), y_(y), dx_(dx), dy_(dy), texture_(texture) {    
    sprite_.setTexture(texture);
    sprite_.setTextureRect(sf::IntRect(col * w, row * h, w, h));
    rect_ = sf::FloatRect(x, y, w, h);
}
