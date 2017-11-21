#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <memory>
#include <stack>


class Display;
class GameState;
class PlayState;
class DelayState;
class GameOverState;
class MainMenuState;


class Application {
public:
    Application();
    ~Application();
    void Run();
    void PushState(GameState *state);
    void PopState();
    void ChangeState(GameState *state);
    void Destroy();
    void ShowFps();
    Display *display_ = nullptr;
    int fps_count_ = 0;
    MainMenuState *main_menu_state_ = nullptr;
    PlayState *play_state_ = nullptr;
    DelayState *delay_state_ = nullptr;
    GameOverState *game_over_state_ = nullptr;
    int human_score_ = 0;
    int computer_score_ = 0;
    std::stack<GameState *> states_;
};

#endif // APPLICATION_H_

