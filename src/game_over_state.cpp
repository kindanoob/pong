#include "application.h"
#include "display.h"
#include "game_over_state.h"
#include <sstream>




GameOverState::GameOverState() {
    InitEntities();
}

void GameOverState::CreateGameOverFont() {
    font_.loadFromFile(kFontsPath + "ubuntu.ttf");
}


void GameOverState::CreateGameOverText(const sf::Font &font, const unsigned int text_size) {
    game_over_text_.setFont(font);
    game_over_text_.setCharacterSize(text_size);
    game_over_text_.setColor(sf::Color::Black);
}


void GameOverState::CreateScoreText(const sf::Font &font, const unsigned int text_size) {
    score_text_.setFont(font);
    score_text_.setCharacterSize(text_size);
    score_text_.setColor(sf::Color::Black);
    score_text_.setPosition(kWindowWidth / 2, kWindowHeight / 2 + 50);
}

void GameOverState::CreatePressAnyKeyText(const sf::Font &font, const unsigned int text_size) {
    press_any_key_text_.setFont(font);
    press_any_key_text_.setCharacterSize(text_size);
    press_any_key_text_.setColor(sf::Color::Black);
    press_any_key_text_.setPosition(kWindowWidth / 2, kWindowHeight / 2 + 125);
    press_any_key_text_.setString("Press Enter to go to the main menu.");
}

void GameOverState::Draw() {};

void GameOverState::Draw(Application *app) {
    app->display_->Draw(game_over_text_);
    app->display_->Draw(score_text_);
    app->display_->Draw(press_any_key_text_);
}


void GameOverState::InitEntities() {
    CreateGameOverFont();
    CreateGameOverText(font_, kGameOverTextSize);
    CreateScoreText(font_, kScoreTextSize);
    CreatePressAnyKeyText(font_, kPressAnyKeyTextSize);
}

void GameOverState::Input() {};

void GameOverState::Input(const sf::Event &event) {}

void GameOverState::Input(Application *app) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        app->PopState();
    }
}

void GameOverState::Update(double dt, Application *app) {
    std::ostringstream game_over_text__stringstream;
    game_over_text__stringstream << "Match is over." << std::endl;
    game_over_text_.setString(game_over_text__stringstream.str());
    sf::FloatRect rect = game_over_text_.getLocalBounds();
    game_over_text_.setOrigin(rect.width / 2, rect.height / 2);
    game_over_text_.setPosition(kWindowWidth / 2, kWindowHeight / 2);

    std::ostringstream score_text__stringstream;
    score_text__stringstream << "Final score: " << std::endl;
    score_text__stringstream << "Player " << app->human_score_ << 
    " : " << app->computer_score_ << " Computer" << std::endl;
    score_text_.setString(score_text__stringstream.str());
    sf::FloatRect score_rect = score_text_.getLocalBounds();
    score_text_.setOrigin(score_rect.width / 2, score_rect.height / 2);
    score_text_.setPosition(kWindowWidth / 2, kWindowHeight / 2 + 
        game_over_text_.getLocalBounds().height);

    sf::FloatRect any_key_rect = press_any_key_text_.getLocalBounds();
    press_any_key_text_.setOrigin(any_key_rect.width / 2, any_key_rect.height / 2);
    press_any_key_text_.setPosition(kWindowWidth / 2, kWindowHeight / 2 + 
        game_over_text_.getLocalBounds().height + score_text_.getLocalBounds().height);
}




