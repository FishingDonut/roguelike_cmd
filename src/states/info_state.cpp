#include <iostream>
#include <sstream>
#include <windows.h>
#include <conio.h>

#include "states/info_state.h"
#include "core/map_value_to_char.h"
#include "core/color_char.h"
#include "core/visual_length.h"
#include "core/render.h"
#include "state_machine.h"
#include "game_data.h"

extern StateMachine nextState;
extern bool stateChanged;


void drawText(string label, int y, Colors color = COLOR_RESET){
    std::stringstream stream;
    stream.str("");
    stream.clear();
    stream << colorChar(color) << label << colorChar(COLOR_RESET);
    
    std::string text = stream.str();
    int textLength = visualLength(text, 0);

    SetConsoleCursorPosition(game_data.hConsole, {(SHORT)((width / 2) - (textLength / 2)), (SHORT)((height / 2) + y)});
    cout << text;
}

void info_enter()
{
    HANDLE hConsole = game_data.hConsole;
    std::stringstream stream;
    auto& config = gameData.config;

    system("cls");
    drawMargin(hConsole);
    
    
    drawText("As salas são geradas aleatoriamente, use armadilhas ou paredes para driblar inimigos.", 1);
    drawText("Suba os andares até que o chefe aparessa, matando ele vc vence o jogo.", 2);
  
    drawText(std::string(1, gameData.player.skin) + " - Jogador", 3, COLOR_YELLOW);
    drawText(std::string(1, Enemy().skin) + " - Inimigo", 4, COLOR_RED);
    drawText(std::string(1, mapValueToChar(STAIR)) + " - Escada", 5);   
    drawText(std::string(1, Trap().visibleSkin) + " - Armadilha", 6, Trap().color);
    
    drawText("Controles", 7);
    drawText(" UP = " + std::string(1, config.UP),8);
    drawText(" DOWN = " + std::string(1, config.DOWN), 9);
    drawText(" LEFT = " + std::string(1, config.LEFT), 10);
    drawText(" RIGHT = " + std::string(1, config.RIGHT), 11);
    drawText(" ATTACK = ESPAÇO", 12);
    drawText(" PAUSE = ESC", 13);
    drawText(" EXIT = Q", 14);


    return;
}

void info_update()
{
    getch();
    nextState = previousState;
    stateChanged = true;
    return;
}

void info_exit()
{
    return;
}