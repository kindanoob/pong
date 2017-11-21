
#include <iostream>
#include <sstream>

#include "application.h"
#include "display.h"
#include "main_menu_state.h"
#include "play_state.h"


MainMenuState::MainMenuState() {
    InitEntities();
}


void MainMenuState::CreateMenuFont() {
    if (!font_.loadFromFile(kFontsPath + "ubuntu.ttf")) {
        std::cout << "Error. Create_menu_font failed to load." << std::endl;
    } else {
        std::cout << "Create_menu_font loaded successfully." << std::endl;
    }
}


void MainMenuState::CreateMenuText(const sf::Font &font, 
    const unsigned int text_size) {
    new_game_text_.setFont(font);
    new_game_text_.setCharacterSize(text_size);
    new_game_text_.setString("New game");
    new_game_text_.setColor(sf::Color::Black);
    sf::FloatRect new_game_text_rect = new_game_text_.getLocalBounds();
    new_game_text_.setOrigin(new_game_text_rect.width / 2, 
        new_game_text_rect.height / 2);
    new_game_text_.setPosition(kWindowWidth / 2, kWindowHeight / 2);
}


void MainMenuState::Input(Application *app) {
    auto mouse_position = app->display_->window_->
        mapPixelToCoords(sf::Mouse::getPosition(*(app->display_->window_)));
    if (menu_rect_.getGlobalBounds().contains(mouse_position)) {
        menu_rect_.setFillColor(sf::Color::Yellow);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            app->PushState(app->play_state_);
        }
    } else {
        menu_rect_.setFillColor(sf::Color::White);
    }
}



void MainMenuState::Input(const sf::Event &event) {}

void MainMenuState::Input() {}


void MainMenuState::Update(double dt, Application *app) {}


void MainMenuState::Draw(Application *app) {
    app->display_->Draw(menu_rect_);
    app->display_->Draw(new_game_text_);
}

void MainMenuState::Draw() {}

void MainMenuState::InitEntities() {
    CreateMenuFont();
    CreateMenuText(font_, kMenuTextSize);
    CreateRect();
}


void MainMenuState::CreateRect() {
    menu_rect_.setSize(sf::Vector2f(200, 75));
    menu_rect_.setFillColor(sf::Color::White);
    menu_rect_.setOutlineThickness(5);
    menu_rect_.setOutlineColor(sf::Color::Black);
    menu_rect_.setOrigin(menu_rect_.getSize().x / 2, menu_rect_.getSize().y / 2);
    menu_rect_.setPosition(kWindowWidth / 2, kWindowHeight / 2);
}
