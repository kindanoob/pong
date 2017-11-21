#include <iostream>
#include "paddle.h"
#include "config.h"
#include "ball.h"


Paddle::Paddle(double x, double y, Player owner) : x_(x), y_(y), owner_(owner) {
    rect_shape_.setSize(sf::Vector2f(kPaddleWidth, kPaddleHeight));
    rect_shape_.setFillColor(sf::Color(150, 100, 50));
    rect_shape_.setOrigin(kPaddleWidth / 2, kPaddleHeight / 2);    
    rect_shape_.setPosition(x_, y_);
    if (owner == Player::kComputer) {
        dy_ = kPaddleDy;
    } else {
        dy_ = 0.0;
    }
}


void Paddle::Update(double dt) {
    y_ += dy_ * dt;
    CheckVerticalCollision();
    rect_shape_.setPosition(sf::Vector2f(x_, y_));
}


void Paddle::CheckVerticalCollision() {
    if (y_ < kOffsetY + kPaddleHeight / 2) {
        y_ = kOffsetY + kPaddleHeight / 2;
    } else if (y_ > kWindowHeight - kOffsetY - kPaddleHeight / 2) {
        y_ = kWindowHeight - kOffsetY - kPaddleHeight / 2;
    }
}

void Paddle::GetPlayerInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        dy_ = -kPaddleDy;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        dy_ = kPaddleDy;
    } else {
        dy_ = 0.0;
    }
}


void Paddle::GetDefaultComputerMove() {
    if (y_ < kOffsetY + kPaddleHeight) {
        dy_ = kPaddleDy;
    } else if (y_ > kWindowHeight - (kOffsetY + kPaddleHeight)) {
        dy_ = -kPaddleDy;
    }
}


void Paddle::GetComputerMove(Ball *ball) {
    if (y_ + kPaddleHeight / 10 < ball->y_) {
        dy_ = kPaddleDy;
    } else if (y_ - kPaddleHeight / 10 > ball->y_) {
        dy_ = -kPaddleDy;
    } else {
        dy_ = 0.0;
    }
}
