#include <iostream>
#include <sstream>
#include "application.h"
#include "display.h"
#include "play_state.h"
#include "delay_state.h"
#include "game_over_state.h"
#include "entity.h"
#include "ball.h"
#include "paddle.h"


PlayState::PlayState(Application *app) {
    InitEntities(app);
};

void PlayState::Input(Application *app) {
    human_paddle_->GetPlayerInput();
    computer_paddle_->GetComputerMove(ball_);
}

void PlayState::Input() {
    human_paddle_->GetPlayerInput();
    computer_paddle_->GetComputerMove(ball_);
};


void PlayState::Input(const sf::Event &event) {};


void PlayState::Update(double dt, Application *app) {
    if (!is_initialized_) {
        is_initialized_ = true;
        start_match_delay_ = kStartMatchDelay;
        app->human_score_ = 0;
        app->computer_score_ = 0;
        clock_.restart();
        return;
    } else {
        if (start_match_delay_ > 0) {
            start_match_delay_-= clock_.getElapsedTime().asMilliseconds();
            clock_.restart();
            start_match_delay_= std::max(0, start_match_delay_);
        } else {
            if (reset_duration_ == 0) {
                ball_->Update(dt, human_paddle_, computer_paddle_);
            } else {
                reset_duration_ -= clock_.getElapsedTime().asMilliseconds();
                clock_.restart();
                reset_duration_ = std::max(0, reset_duration_);
            }
        }
    }

    human_paddle_->Update(dt);
    computer_paddle_->Update(dt);
    UpdateScore(app);
    UpdateFpsCount(app);
};


void PlayState::Draw(Application *app) {
    app->display_->Draw(field_rect_);
    app->display_->Draw(ball_->ball_shape_);
    app->display_->Draw(human_paddle_->rect_shape_);
    app->display_->Draw(computer_paddle_->rect_shape_);
    app->display_->Draw(score_text_);
    app->display_->Draw(fps_count_text_);    
};

void PlayState::Draw() {}

void PlayState::InitEntities(Application *app) {
    CreateField();
    CreateBall();
    CreateHumanPaddle();
    CreateComputerPaddle();
    CreateFont();
    CreateScoreText(font_, kScoreTextSize, app);
    CreateFpsCountText(font_, kScoreTextSize, app);
}


void PlayState::CreateField() {
    field_rect_.setSize(sf::Vector2f(kFieldWidth, kFieldHeight));
    field_rect_.setPosition(100, 100);
    field_rect_.setFillColor(sf::Color::Yellow);
    field_rect_.setOutlineThickness(kFieldBorderThickness);
    field_rect_.setOutlineColor(sf::Color::Black);
}


void PlayState::CreateBall() {
    ball_ = new Ball();
}


void PlayState::CreateHumanPaddle() {
    human_paddle_ = new Paddle(kOffsetX + 2 * kPaddleWidth, 
        kWindowHeight / 2, Player::kHuman);
}


void PlayState::CreateComputerPaddle() {
    computer_paddle_ = new Paddle(kWindowWidth - (kOffsetX + 2 * kPaddleWidth), 
        kWindowHeight / 2, Player::kComputer);
}


void PlayState::CreateScoreText(const sf::Font &font, 
    const unsigned int text_size, Application *app) {
    score_text_.setFont(font);
    score_text_.setCharacterSize(text_size);
    score_text_.setColor(sf::Color::Black);
    score_text_.setPosition(kOffsetX, kOffsetY / 2);
    std::ostringstream score_text_stringstream;
    score_text_stringstream << "Player " << app->human_score_ << 
    " : " << app->computer_score_ << " Computer" << std::endl;
    score_text_.setString(score_text_stringstream.str());
}


void PlayState::CreateFont() {
    font_.loadFromFile(kFontsPath + "ubuntu.ttf");
}


void PlayState::UpdateScore(Application *app) {
    if (ball_->x_ - kBallRadius <= kOffsetX) {
        ++(app->computer_score_);
        ball_->Reset();
        clock_.restart();
        reset_duration_ = kResetDuration;
    } else if (ball_->x_ + kBallRadius >= kWindowWidth - kOffsetX) {
        ++(app->human_score_);
        ball_->Reset();
        clock_.restart();
        reset_duration_ = kResetDuration;
    }
    std::ostringstream score_text_stringstream;
    score_text_stringstream << "Player " << app->human_score_ << " : " << app->computer_score_ << " Computer" << std::endl;
    score_text_.setString(score_text_stringstream.str());
    if (std::max(app->human_score_, app->computer_score_) == kMatchWinnerScore) {
        is_initialized_ = false;
        app->ChangeState(app->game_over_state_);
    }
}


void PlayState::CreateFpsCountText(const sf::Font &font, const unsigned int text_size, Application *app) {
    fps_count_text_.setFont(font);
    fps_count_text_.setCharacterSize(text_size);
    fps_count_text_.setColor(sf::Color::Black);
    fps_count_text_.setPosition(kWindowWidth - 2 * kOffsetX, kOffsetY / 2);
    std::ostringstream fps_count_text_stringstream;
    fps_count_text_stringstream << "FPS: " << app->fps_count_ << std::endl;
    fps_count_text_.setString(fps_count_text_stringstream.str());
}


void PlayState::UpdateFpsCount(Application *app) {
    std::ostringstream fps_count_text_stringstream;
    fps_count_text_stringstream << "FPS: " << app->fps_count_ << std::endl;
    fps_count_text_.setString(fps_count_text_stringstream.str());
}
