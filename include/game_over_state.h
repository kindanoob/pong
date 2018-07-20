#ifndef GAME_OVER_H_
#define GAME_OVER_H_

#include "game_state.h"
#include <SFML/Graphics.hpp>

class Application;

class GameOverState: public GameState {
public:
    GameOverState();
    void CreateGameOverText(const sf::Font& font, const unsigned int text_size);
    void CreateScoreText(const sf::Font& font, const unsigned int text_size);
    void CreatePressAnyKeyText(const sf::Font& font, const unsigned int text_size);
    void CreateGameOverFont();
    void Input();
    void Input(const sf::Event& event);
    void Input(Application *app);
    void Update(double dt, Application *app);
    void Draw();
    void Draw(Application *app);
    void InitEntities();
public:
    sf::Font font_;
    sf::Text game_over_text_;
    sf::Text score_text_;
    sf::Text press_any_key_text_;
    sf::RectangleShape field_rect_;
};

#endif // GAME_OVER_H_