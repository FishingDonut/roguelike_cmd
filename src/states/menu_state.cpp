#include <iostream>
#include "states/menu_state.h"
#include "stateMachine.h"

extern StateMachine nextState;
extern bool stateChanged;

void menu_enter() {
    std::cout << "Entrando no MENU\n";
}

void menu_update() {
    std::cout << "Atualizando o MENU\n";
    std::cout << "Pressione Enter para jogar...\n";
    std::cin.get();
    nextState = STATE_PLAYING;
    stateChanged = true;
}

void menu_exit() {
    std::cout << "Saindo do MENU\n";
}