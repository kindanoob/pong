#ifndef DELAY_STATE_H_
#define DELAY_STATE_H_

#include "game_state.h"


class Application;


class DelayState: public GameState {
public:
    DelayState(Application *app);
    void Input(const sf::Event &event);
    void Input();
    void Update(double dt);
    void Draw();
};


#endif // DELAY_STATE_H_
