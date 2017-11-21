#ifndef PADDLE_H_
#define PADDLE_H_

#include <SFML/Graphics.hpp>

class Ball;

enum class Player {
    kHuman, 
    kComputer
};


class Paddle {
public:
    sf::RectangleShape rect_shape_;
    Paddle(double x, double y, Player player);
    Player owner_ = Player::kHuman;
    double x_ = 0.0;
    double y_ = 0.0;
    double dx_ = 0.0;
    double dy_ = 0.0;
    void Update(double dt);
    void CheckVerticalCollision();
    void GetPlayerInput();
    void GetDefaultComputerMove();
    void GetComputerMove(Ball *ball);
};

#endif // PADDLE_H
