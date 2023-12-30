#ifndef PLAYER_H
#define PLAYER_H
#include <stdint.h>

struct Player {
    struct Card *hand;
    uint8_t maxHandSize;
    uint8_t handSize;
};

#endif
