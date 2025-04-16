Perfeito! Se você está evitando **classes, ponteiros e ponteiros de função**, dá pra fazer um sistema de `GameState` estilo **C-style em C++**, usando `structs` e talvez um `enum` para controlar o estado atual do jogo. É totalmente viável e ainda assim modular.

---

### 🧱 Estrutura com `struct` e `enum`

#### 1. **Enum com os estados do jogo:**

```cpp
// include/gamestate.h
#pragma once

enum GameState {
    STATE_MENU,
    STATE_PLAYING,
    STATE_GAME_OVER
};
```

---

#### 2. **Funções separadas por estado**

Você cria arquivos com funções específicas para cada estado:

```cpp
// include/states/menu_state.h
#pragma once

void menu_handle_input();
void menu_update();
void menu_render();
```

```cpp
// include/states/play_state.h
#pragma once

void play_handle_input();
void play_update();
void play_render();
```

---

#### 3. **Loop principal controlando os estados**

```cpp
// src/main.cpp
#include <iostream>
#include "gamestate.h"
#include "states/menu_state.h"
#include "states/play_state.h"

GameState current_state = STATE_MENU;

void game_loop() {
    bool running = true;

    while (running) {
        switch (current_state) {
            case STATE_MENU:
                menu_handle_input();
                menu_update();
                menu_render();
                break;

            case STATE_PLAYING:
                play_handle_input();
                play_update();
                play_render();
                break;

            case STATE_GAME_OVER:
                running = false;  // Exemplo simples
                break;
        }
    }
}

int main() {
    game_loop();
    return 0;
}
```

---

#### 4. **Exemplo simples de um estado**

```cpp
// src/states/menu_state.cpp
#include <iostream>
#include "states/menu_state.h"
#include "gamestate.h"

extern GameState current_state;

void menu_handle_input() {
    std::cout << "Pressione Enter para jogar..." << std::endl;
    std::cin.get();
    current_state = STATE_PLAYING;
}

void menu_update() {
    // Nada por enquanto
}

void menu_render() {
    std::cout << "=== MENU ===" << std::endl;
}
```

---

### 📁 Organização sugerida

```
include/
│   gamestate.h
│   states/
│       menu_state.h
│       play_state.h
│
src/
│   main.cpp
│   states/
│       menu_state.cpp
│       play_state.cpp
```

---

### ✅ Vantagens desse modelo

- Fácil de entender e debugar.
- Não usa ponteiros, nem OO pesada.
- Modular: cada estado em seu próprio arquivo.
- Escalável: você só adiciona mais `case` no switch e arquivos novos.

Se quiser, posso te ajudar a montar um exemplo completo com Makefile e tudo. Quer?