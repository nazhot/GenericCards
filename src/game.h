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

/**
 * Initialize a new Game with default settings
 *
 * The first Player will be the default starter, Decks won't be set to anything
 * in the beginning, that will be up to the programmer to initialize.
 *
 * @param numPlayers how many Players are in the Game
 * @param numDecks how many Decks are in the Game
 * @return pointer to the created Game
 */
struct Game* game_initialize( uint8_t numPlayers, uint8_t numDecks );

#endif
