#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "game_state.h"
#include <SFML/Graphics.hpp>

class Application;

class MainMenuState: public GameState {
public:
    MainMenuState();
    sf::Font font_;
    sf::Text menu_text_;
    sf::Text new_game_text_;
    sf::RectangleShape menu_rect_;
    sf::RectangleShape new_game_button_rect_;
    void CreateMenuText(const sf::Font &font, const unsigned int text_size);
    void CreateMenuFont();
    void CreateRect();    
    void Input(const sf::Event &event);
    void Input();
    void Input(Application *app);
    void Update(double dt, Application *app);
    void Draw();
    void Draw(Application *app);
    void Init();
    void InitEntities();
};

#endif // MAIN_MENU_H_
