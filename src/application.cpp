#include <iostream>
#include "application.h"
#include "display.h"
#include "game_state.h"
#include "play_state.h"
#include "delay_state.h"
#include "game_over_state.h"
#include "main_menu_state.h"



Application::Application() {
    std::cout << "Application()" << std::endl;
    display_ = new Display();
    main_menu_state_ = new MainMenuState();
    PushState(main_menu_state_);
    play_state_ = new PlayState(this);
    game_over_state_ = new GameOverState();
}

Application::~Application() {
    std::cout << "~Application()" << std::endl;
}

void Application::Run() {
    sf::Clock clock;
    while (display_->IsOpen()) {
        unsigned long long time = clock.getElapsedTime().asMicroseconds();
        if (time % 100 == 0) {
            fps_count_ = 1000000.0 / time;
        }
        //show_fps();
        double dt = time / kTimeAdjustmentCoeff;
        clock.restart();
        display_->CheckWindowEvents();
        display_->Clear();
        states_.top()->Input(this);
        states_.top()->Update(dt, this);
        states_.top()->Draw(this);
        display_->DisplayWindow();
    }
    display_->Destroy();
}


void Application::PushState(GameState *state) {
    states_.push(state);
};


void Application::PopState() {
    states_.pop();
};


void Application::ChangeState(GameState *state) {
    states_.pop();
    states_.push(state);
};


void Application::Destroy() {
    delete play_state_;
}


void Application::ShowFps() {
    std::cout << "FPS: " << fps_count_ << std::endl;
}
