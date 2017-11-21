#ifndef ENTITY_H_
#define ENTITY_H_


#include <string>
#include <SFML/Graphics.hpp>

class Entity {
public:
    int w_ = 0;
    int h_ = 0;
    int x_ = 0;
    int y_ = 0;
    double dx_ = 0.0;
    double dy_ = 0.0;
    bool is_alive_ = true;
    int health_ = 0;
    int damage_ = 0;
    std::string name_ = "";
    sf::Texture texture_;
    sf::Sprite sprite_;
    sf::FloatRect rect_;
    Entity(const sf::Texture &texture, const std::string &name, 
        int x, int y, double dx, double dy, 
        int w, int h, int row, int col);
};

#endif // ENTITY_H_
