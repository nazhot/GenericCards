#ifndef DECK_H
#define DECK_H
#include <cstdint>
#include <stdbool.h>

enum EmptyDeckOption {
    EDO_END_GAME,
    EDO_SHUFFLE,
    EDO_DEAL_HANDS
};

struct Deck {
    unsigned int numCards;
    struct Card *cards;
    enum EmptyDeckOption whenEmpty; 
};

/**
 * Initialize a deck, using an int to represent the cards within it
 *
 * Each Card is represented by a bit within the int. The ordering is Ace through
 * King, and Diamonds, Clubs, Hearts, Spades.
 *
 * @param cards bits representing the Cards present in the deck
 * @return pointer to the created Deck
 */
struct Deck* deck_initializeFromInt( uint64_t cards );

/**
 * Initialize a standard deck, with Ace through King, all Suits
 *
 * @return pointer to the created Deck
 */
struct Deck* deck_initializeStandard();

bool deck_addCard( struct Deck *deck, uint8_t card );

#endif
