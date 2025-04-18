#include <iostream>
#include <conio.h>
#include <windows.h>

#include "global.h"
#include "states/map_construction_state.h"
#include "stateMachine.h"
#include "GameData.h"
#include "include/map_construction/generate_rooms.h"

extern StateMachine nextState;
extern bool stateChanged;

void map_construction_enter(){
    generate_rooms();
    return;
};

void map_construction_update(){
    nextState = STATE_PLAYING;
    stateChanged = true;
    return;
};

void map_construction_exit(){
    return;
};