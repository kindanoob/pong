#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include <list>
#include <SFML/Graphics.hpp>
#include "game_state.h"

class Ball;
class Paddle;
class Application;



class PlayState: public GameState {
public:
    PlayState(Application *app);
    Ball *ball_ = nullptr;
    Paddle *human_paddle_ = nullptr;
    Paddle *computer_paddle_ = nullptr;
    sf::Font font_;
    sf::Text score_text_;
    sf::Text fps_count_text_;
    int start_match_delay_ = kStartMatchDelay;
    int reset_duration_ = 0;
    sf::Clock clock_;
    bool is_initialized_ = false;
    sf::RectangleShape field_rect_;

    void CreateScoreText(const sf::Font &font, const unsigned int text_size, Application *app);
    void CreateFont();
    void Input();
    void Input(Application *app);
    void Input(const sf::Event &event);
    void Update(double dt);
    void Update(double dt, Application *app);
    void Draw();
    void Draw(Application *app);
    void InitEntities(Application *app);
    void CreateField();
    void CreateBall();
    void CreateHumanPaddle();
    void CreateComputerPaddle();
    void UpdateScore(Application *app);
    void CreateFpsCountText(const sf::Font &font, const unsigned int text_size, Application *app);
    void UpdateFpsCount(Application *app);
};

#endif // PLAY_STATE_H_
