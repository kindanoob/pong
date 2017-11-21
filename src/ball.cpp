#include <iostream>
#include <time.h>
#include <SFML/System.hpp>
#include "ball.h"
#include "paddle.h"
#include "util.h"


Ball::Ball() {
    ball_shape_.setRadius(kBallRadius);
    ball_shape_.setFillColor(sf::Color(50, 100, 150));
    ball_shape_.setOrigin(kBallRadius, kBallRadius);
    ball_shape_.setPosition(x_, y_);
    srand(time(nullptr));
    dx_ = kBallDx;
    dy_ = kBallDy;
}


void Ball::Update(double dt, Paddle *player_paddle, Paddle *bot_paddle) {
    if (time_after_spawn_ < 1000) {
        if (fabs(dx_) < kBallDx) {
            double sign_dx_ = dx_ / fabs(dx_);
            dx_ += sign_dx_ * dt / 2000;
            if(fabs(dx_) > kBallDx){
                dx_ = sign_dx_ * kBallDx;
            }
        }
        if (fabs(dy_) < kBallDy) {
            double sign_dy_ = dy_ / fabs(dy_);
            dy_ += sign_dy_ * dt / 2000;
            if (fabs(dy_) > kBallDy) {
                dy_ = sign_dy_ * kBallDy;
            }
        }
        time_after_spawn_ += dt;
    }
    x_ += dx_ * dt;
    y_ += dy_ * dt;
    CheckCollisionWithField(CollisionDirection::kHorizontal);
    CheckCollisionWithField(CollisionDirection::kVertical);
    CheckCollisionWithPaddle(player_paddle, CollisionDirection::kHorizontal);
    CheckCollisionWithPaddle(player_paddle, CollisionDirection::kVertical);
    CheckCollisionWithPaddle(bot_paddle, CollisionDirection::kHorizontal);
    CheckCollisionWithPaddle(bot_paddle, CollisionDirection::kVertical);
    ball_shape_.setPosition(sf::Vector2f(x_, y_));
}

void Ball::CheckCollisionWithField (CollisionDirection dir) {
    if (dir == CollisionDirection::kHorizontal) {
        if (x_ < kOffsetX + kBallRadius) {
            x_ = kOffsetX + kBallRadius;
            dx_ *= -1;
        } else if (x_ > kWindowWidth - kOffsetX - kBallRadius) {
            x_ = kWindowWidth - kOffsetX - kBallRadius;
            dx_ *= -1;
        }
    } else if (dir == CollisionDirection::kVertical) {
        if (y_ < kOffsetY + kBallRadius) {
            y_ = kOffsetY + kBallRadius;
            dy_ *= -1;
        } else if (y_ > kWindowHeight - kOffsetY - kBallRadius) {
            y_ = kWindowHeight - kOffsetY - kBallRadius;
            dy_ *= -1;
        }
    }
}


double DistSquared(double x0, double y0, double x1, double y1) {
    double x_diff = x0 - x1;
    double y_diff = y0 - y1;
    return x_diff * x_diff + y_diff * y_diff;
}

void Ball::CheckCollisionWithPaddle(Paddle *paddle, CollisionDirection dir) {
    if (paddle->owner_ == Player::kHuman) {
        if (dir == CollisionDirection::kHorizontal) {
            if ((dx_ < 0) && (x_ - kBallRadius <= paddle->x_ + kPaddleWidth / 2)) {
                    double dist_front = x_ - (paddle->x_ - kPaddleWidth / 2);
                    double dist_squared_top_right = DistSquared(x_, y_, paddle->x_ + kPaddleWidth / 2, 
                        paddle->y_ - kPaddleHeight / 2);
                    double dist_squared_bottom_right = DistSquared(x_, y_, paddle->x_ + kPaddleWidth / 2, 
                        paddle->y_ + kPaddleHeight / 2);
                    int r_squared = kBallRadius * kBallRadius;
                    if ((dist_squared_top_right <= r_squared) || 
                        (dist_squared_bottom_right <= r_squared) || 
                        (fabs(y_ - paddle->y_) <= kPaddleHeight / 2)) {
                        x_ = paddle->x_ + kPaddleWidth / 2 + dist_front;
                        dx_ *= -1;
                    }
            }
        } else if (dir == CollisionDirection::kVertical) {
            if ((dy_ > 0) && (y_ + kBallRadius >= paddle->y_ - kPaddleHeight / 2) && (y_ + kBallRadius < paddle->y_ + kPaddleHeight / 2)) {
                double dist_top = paddle->y_ - kPaddleHeight / 2 - y_;
                double dist_squared_top_right = DistSquared(x_, y_, paddle->x_ + kPaddleWidth / 2, paddle->y_ - kPaddleHeight / 2);
                double dist_squared_top_left = DistSquared(x_, y_, paddle->x_ - kPaddleWidth / 2, paddle->y_ - kPaddleHeight / 2);
                int r_squared = kBallRadius * kBallRadius;
                if ((dist_squared_top_left <= r_squared) || 
                    (dist_squared_top_right <= r_squared) || 
                    (fabs(x_ - paddle->x_) <= kPaddleWidth / 2)) {
                    y_ = paddle->y_ - kPaddleHeight / 2 - dist_top;
                    dy_ *= -1;
                }
            } else if ((dy_ <= 0) && (y_ - kBallRadius <= paddle->y_ + kPaddleHeight / 2) && (y_ - kBallRadius > paddle->y_ - kPaddleHeight / 2)) {
                double dist_bottom = y_ - (paddle->y_ + kPaddleHeight / 2);
                double dist_squared_bottom_right = DistSquared(x_, y_, paddle->x_ + kPaddleWidth / 2, paddle->y_ + kPaddleHeight / 2);
                double dist_squared_bottom_left = DistSquared(x_, y_, paddle->x_ - kPaddleWidth / 2, paddle->y_ + kPaddleHeight / 2);
                int r_squared = kBallRadius * kBallRadius;
                if ((dist_squared_bottom_left <= r_squared) || 
                    (dist_squared_bottom_right <= r_squared) || 
                    (fabs(x_ - paddle->x_) <= kPaddleWidth / 2)) {
                    y_ = paddle->y_ + kPaddleHeight / 2 + dist_bottom;
                    dy_ *= -1;
                }
            }
        }
    }
    else if (paddle->owner_ == Player::kComputer) {
        if (dir == CollisionDirection::kHorizontal) {
            if ((dx_ > 0) && (x_ + kBallRadius >= paddle->x_ - kPaddleWidth / 2)) {
                double dist_front = paddle->x_ - kPaddleWidth / 2 - x_;
                double dist_squared_top_left = DistSquared(x_, y_, paddle->x_ - kPaddleWidth / 2, paddle->y_ - kPaddleHeight / 2);
                double dist_squared_bottom_left = DistSquared(x_, y_, paddle->x_ - kPaddleWidth / 2, paddle->y_ + kPaddleHeight / 2);
                int r_squared = kBallRadius * kBallRadius;
                if ((dist_squared_top_left <= r_squared) || 
                    (dist_squared_bottom_left <= r_squared) || 
                    (fabs(y_ - paddle->y_) <= kPaddleHeight / 2)) {
                    x_ = paddle->x_ - kPaddleWidth / 2 - dist_front;
                    dx_ *= -1;
                }
            }
        } else if (dir == CollisionDirection::kVertical) {
            if ((dy_ > 0) && (y_ + kBallRadius >= paddle->y_ - kPaddleHeight / 2) && (y_ + kBallRadius < paddle->y_ + kPaddleHeight / 2)) {
                double dist_top = paddle->y_ - kPaddleHeight / 2 - y_;
                double dist_squared_top_right = DistSquared(x_, y_, paddle->x_ + kPaddleWidth / 2, paddle->y_ - kPaddleHeight / 2);
                double dist_squared_top_left = DistSquared(x_, y_, paddle->x_ - kPaddleWidth / 2, paddle->y_ - kPaddleHeight / 2);
                int r_squared = kBallRadius * kBallRadius;
                if ((dist_squared_top_left <= r_squared) || 
                    (dist_squared_top_right <= r_squared) || 
                    (fabs(x_ - paddle->x_) <= kPaddleWidth / 2)) {
                    y_ = paddle->y_ - kPaddleHeight / 2 - dist_top;
                    dy_ *= -1;
                }
            } else if ((dy_ <= 0) && (y_ - kBallRadius <= paddle->y_ + kPaddleHeight / 2) && (y_ - kBallRadius > paddle->y_ - kPaddleHeight / 2)) {
                double dist_bottom = y_ - (paddle->y_ + kPaddleHeight / 2);
                double dist_squared_bottom_right = DistSquared(x_, y_, paddle->x_ + kPaddleWidth / 2, paddle->y_ + kPaddleHeight / 2);
                double dist_squared_bottom_left = DistSquared(x_, y_, paddle->x_ - kPaddleWidth / 2, paddle->y_ + kPaddleHeight / 2);
                int r_squared = kBallRadius * kBallRadius;
                if ((dist_squared_bottom_left <= r_squared) || 
                    (dist_squared_bottom_right <= r_squared) || 
                    (fabs(x_ - paddle->x_) <= kPaddleWidth / 2)) {
                    y_ = paddle->y_ + kPaddleHeight / 2 + dist_bottom;
                    dy_ *= -1;
                }
            }
        }
    }
}


void Ball::Reset() {
    x_ = kWindowWidth / 2;
    y_ = kWindowHeight / 2;
    dx_ = kBallDx / 100;
    dy_ = kBallDy / 100;
    if (GetRandomInt(0, 1) % 2) {
        dx_ *= -1;
    }
    if (GetRandomInt(0, 1) % 2) {
        dy_ *= -1;
    }
    time_after_spawn_ = 0;
    ball_shape_.setPosition(x_, y_);
}


