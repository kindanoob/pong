#include "application.h"
#include "display.h"
#include "play_state.h"
#include "delay_state.h"
#include "entity.h"
#include "ball.h"
#include "paddle.h"



DelayState::DelayState(Application *app): GameState() {};


void DelayState::Input(const sf::Event &event) {};
void DelayState::Input() {};
void DelayState::Update(double dt) {};
void DelayState::Draw() {};
