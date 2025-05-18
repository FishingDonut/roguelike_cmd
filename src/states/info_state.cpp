#include <iostream>
#include <sstream>

#include "states/info_state.h"
#include "core/map_value_to_char.h"
#include "core/color_char.h"
#include "core/visual_length.h"
#include "core/render.h"
#include "state_machine.h"
#include "game_data.h"
#include "BearLibTerminal.h"

extern StateMachine nextState;
extern bool stateChanged;

void drawText(const std::string &label, int y)
{
    int textLength = visualLength(label, 0);
    int x = ((width / 2) - (textLength / 2));
    y = ((height / 2) + y);
    terminal_printf(x, y, "%s", label.c_str());
}

void info_enter()
{
    std::stringstream stream;
    auto &config = gameData.config;

    terminal_clear();
    drawMargin();

    drawText("As salas são geradas aleatoriamente, use armadilhas ou paredes para driblar inimigos.", 1);
    drawText("Suba os andares até que o chefe aparessa, matando ele vc vence o jogo.", 2);

    drawText(std::string(1, gameData.player.skin) + " - Jogador", 3);
    drawText(std::string(1, Enemy().skin) + " - Inimigo", 4);
    drawText(std::string(1, mapValueToChar(STAIR)) + " - Escada", 5);
    drawText(std::string(1, Trap().visibleSkin) + " - Armadilha", 6);

    drawText("Controles", 7);
    drawText(" UP = " + std::string(1, config.UP), 8);
    drawText(" DOWN = " + std::string(1, config.DOWN), 9);
    drawText(" LEFT = " + std::string(1, config.LEFT), 10);
    drawText(" RIGHT = " + std::string(1, config.RIGHT), 11);
    drawText(" ATTACK = [ESPAÇO]", 12);
    drawText(" PAUSE = [ESC]", 13);
    drawText(" EXIT = [Q]", 14);

    terminal_refresh();
    return;
}

void info_update()
{
    terminal_read();
    nextState = previousState;
    stateChanged = true;
    return;
}

void info_exit()
{
    return;
}