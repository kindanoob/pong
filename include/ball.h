#ifndef BALL_H_
#define BALL_H_


#include <SFML/Graphics.hpp>
#include "config.h"

enum class CollisionDirection {
    kHorizontal, 
    kVertical
};

class Paddle;

class Ball {
public:
    Ball();
    void Update(double time, Paddle *player_paddle, Paddle *bot_paddle);
    void CheckCollisionWithField(CollisionDirection dir);
    void CheckCollisionWithPaddle(Paddle *paddle, CollisionDirection dir);
    void Reset();
public:
    sf::CircleShape ball_shape_;
    double x_ = kWindowWidth / 2;
    double y_ = kWindowHeight / 2;
    double dx_ = 0.0;
    double dy_ = 0.0;
    double time_after_spawn_ = 0.0;
};

#endif // BALL_H_
