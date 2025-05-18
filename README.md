# roguelike_cmd


### Descrição.

Tramalho da Univali M1.
Feito sozinho.

## Links

Instruções do trabalho [link](https://onedrive.live.com/?redeem=aHR0cHM6Ly8xZHJ2Lm1zL2IvYy8xYmIzM2I2ZDE1MGRiOTBiL0VRVnV6cEU1TG5OSnUyZkJCa3JRRTNjQnp5a25GWllRVVJtd0ZWcU9vdW5EbFE%5FZT1CQ1ZBZjc&cid=1BB33B6D150DB90B&id=1BB33B6D150DB90B%21s91ce6e052e394973bb67c1064ad01377&parId=1BB33B6D150DB90B%2141466&o=OneUp).

Codigo de exemplo do professor [link](https://github.com/alexrese/roguelike).

## Estrtutura do projeto

```
/root
├── include/                            # Cabeçalhos (.h) com declarações e interfaces do projeto
│   ├── game_data.h                      # Struct principal contendo os dados do jogo (jogador, mapa, inimigos etc.)

│   ├── mapData.h                       # Estrutura ou constantes específicas do mapa
│   ├── state_machine.h                  # Declaração da máquina de estados do jogo
│
│   ├── core/                           # Funções e lógica centrais e independentes de estados
│   │   ├── init.h                      # Inicialização de variáveis e recursos
│   │   ├── mapValueToChar.h            # Conversão de valores do mapa para caracteres visuais
│   │   └── render.h                    # Funções de renderização do mapa geral
│
│   ├── entity/                         # Entidades do jogo (jogador, inimigos, salas)
│   │   ├── enemy.h                     # Lógica/estrutura de inimigos
│   │   ├── player.h                    # Estrutura e funções do jogador
│   │   └── room.h                      # Representação de salas no mapa
│
│   ├── map_construction/               # Lógica de geração procedural de mapas
│   │   ├── clear_map.h                  # Função para limpar o mapa
│   │   ├── connect_room.h               # Conectar salas com corredores
│   │   ├── create_room.h                # Criação de uma única sala
│   │   ├── generate_rooms.h            # Geração geral de múltiplas salas
│   │   ├── generate_enemy.h             # Spawning de inimigos
│   │   ├── generate_random_room.h        # Criar uma sala aleatória
│   │   ├── is_colliding.h               # Verifica colisões entre salas
│   │   ├── map_construction.h          # Header geral para incluir todos acima
│   │   └── set_position_player.h       # Define posição inicial do jogador
│
│   ├── playing/                        # Lógica durante o estado de jogo ativo
│   │   ├── input.h                     # Captura e interpretação de input do jogador
│   │   ├── render.h                    # Renderização específica do estado "jogando"
│   │   └── update_logic.h              # Atualização de movimentação e eventos
│
│   ├── states/                         # Definições dos estados do jogo
│   │   ├── game_over_state.h           # Estado de fim de jogo
│   │   ├── map_construction_state.h    # Estado que gera o mapa antes do gameplay
│   │   ├── menu_state.h                # Tela de menu inicial
│   │   ├── paused_state.h              # Estado de pausa
│   │   └── playing_state.h             # Estado ativo de gameplay
│
│   └── tools/                          # Ferramentas utilitárias
│       ├── debug_matriz.h               # Funções de debug para imprimir matrizes
│       └── get_char_at_position.h         # Retorna caractere em certa posição no mapa
│
├── src/                                # Implementações (.cpp) das funções declaradas em include/
│   ├── core/
│   │   ├── init.cpp
│   │   ├── mapValueToChar.cpp
│   │   └── render.cpp
│
│   ├── map_construction/
│   │   ├── clearMap.cpp
│   │   ├── connectRoom.cpp
│   │   ├── createRoom.cpp
│   │   ├── generate_rooms.cpp
│   │   ├── generate_enemy.cpp
│   │   ├── generateRandomRoom.cpp
│   │   ├── isColliding.cpp
│   │   └── set_position_player.cpp
│
│   ├── playing/
│   │   ├── input.cpp
│   │   ├── render.cpp
│   │   └── update_logic.cpp
│
│   ├── states/
│   │   ├── game_over_state.cpp
│   │   ├── map_construction_state.cpp
│   │   ├── menu_state.cpp
│   │   ├── paused_state.cpp
│   │   └── playing_state.cpp
│
│   ├── tools/
│   │   ├── debug_matriz.cpp
│   │   └── get_char_at_position.cpp
│
│   └── global.cpp                      # Implementação de variáveis/funções globais
│
├── main.cpp                            # Arquivo principal; inicializa o jogo e a máquina de estados
├── main.exe                            # Binário gerado após a compilação
├── a.bat                               # Script de build ou execução rápida (provavelmente no Windows)
├── Makefile                            # Regras de compilação (para `make`)
└── README.md                           # Documentação do projeto (como compilar, jogar, etc.)
```

## Status

Data de inicio: [14/04/2025]

Data de finalização: [14/04/2025]

# Creditos

| [Daniel](https://github.com/FishingDonut/)

![GitHub top language](https://img.shields.io/github/languages/top/FishingDonut/roguelike_cmd)
![GitHub commit activity](https://img.shields.io/github/commit-activity/t/FishingDonut/roguelike_cmd)
![GitHub last commit](https://img.shields.io/github/last-commit/FishingDonut/roguelike_cmd)