#pragma once

enum StateMachine
{
    STATE_MENU,
    STATE_INFO,
    STATE_DIFFICULTY,
    STATE_SCORE,
    STATE_MAP_CONSTRUCTION,
    STATE_LEVEL_UP,
    STATE_PLAYING,
    STATE_PAUSED,
    STATE_GAME_OVER,
    STATE_CREDITS
};

extern StateMachine currentState;
extern StateMachine nextState;
extern StateMachine previousState;

extern bool stateChanged;