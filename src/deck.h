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
    unsigned int maxCards;
    struct Card *cards;
    enum EmptyDeckOption whenEmpty; 
};

/**
 * Initialize a Deck, without any Cards, specifying the maximum amount of Cards
 * that can ever be in the Deck
 *
 * @parameter maxCards how many Cards the Deck can ever hold
 * @return pointer to the created Deck
 */
struct Deck* deck_initializeEmpty( uint16_t maxCards );

/**
 * Initialize a Deck, using an int to represent the Cards within it
 *
 * Each Card is represented by a bit within the int. The ordering is Ace through
 * King, and Diamonds, Clubs, Hearts, Spades.
 *
 * @param cards bits representing the Cards present in the Deck
 * @return pointer to the created Deck
 */
struct Deck* deck_initializeFromInt( uint64_t cards );

/**
 * Initialize a standard Deck, with Ace through King, all Suits
 *
 * @return pointer to the created Deck
 */
struct Deck* deck_initializeStandard();

/**
 * Add a Card to a Deck, using an int to represent the Card
 *
 * Each Card is represented by a bit within the int. The ordering is Ace through
 * King, and Diamonds, Clubs, Hearts, Spades.
 *
 * @param deck pointer to the Deck
 * @param card representing the Card to add to the Deck
 * @return whether the function was able to add the Card or not
 */
bool deck_addCard( struct Deck *deck, uint8_t card );

/**
 * Add Cards to a Deck, using an int to represent the Cards
 *
 * Each Card is represented by a bit within the int. The ordering is Ace through
 * King, and Diamonds, Clubs, Hearts, Spades.
 *
 * @param pointer to the Deck
 * @param cards bits representing the Cards to add to the Deck
 * @return whether the function was able to add the Cards or not
 */
bool deck_addCards( struct Deck *deck, uint64_t cards );

void deck_shuffle( struct Deck *deck );

#endif
