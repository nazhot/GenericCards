#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <stdint.h>

struct Game {
    uint8_t numPlayers;
    struct Player *players;
    uint8_t currentPlayerIndex;
    struct Deck **decks;
    uint8_t numDecks;
};

#endif
