#pragma once

enum StateMachine {
    STATE_MENU,
    STATE_PLAYING,
    STATE_GAME_OVER
};

extern StateMachine currentState;
extern StateMachine nextState;
extern bool stateChanged;