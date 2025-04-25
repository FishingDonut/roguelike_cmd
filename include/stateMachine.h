#pragma once

enum StateMachine {
    STATE_MENU,
    STATE_INFO,
    STATE_MAP_CONSTRUCTION,
    STATE_PLAYING,
    STATE_PAUSED,
    STATE_GAME_OVER
};

extern StateMachine currentState;
extern StateMachine nextState;
extern StateMachine previousState;

extern bool stateChanged;