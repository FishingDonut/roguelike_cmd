#include <iostream>
#include "states/playing_state.h"
#include "stateMachine.h"

void playing_enter() {
    std::cout << "Entrando no playing\n";
}

void playing_update() {
    std::cout << "Atualizando o playing\n";
    std::cout << "Pressione Enter para jogar...\n";
    std::cin.get();
    nextState = STATE_GAME_OVER;
    stateChanged = true;
}

void playing_exit() {
    std::cout << "Saindo do playing\n";
}