#include "deck.h"
#include <stdlib.h>
#include <stdio.h>




Deck* deck_initializeEmpty( uint maxCards ) {
    Deck *deck = malloc( sizeof( Deck ) );
    if ( !deck ) {
        fprintf( stderr, "Cannot initialize deck of size %u\n", maxCards );
        exit( 1 );
    }
    deck->cards = malloc( sizeof( Card ) * maxCards );
    if ( !deck->cards ) {
        fprintf( stderr, "Cannot initialize cards with size %u\n", maxCards );
        exit( 1 );
    }
    deck->maxCards = maxCards;
    deck->numCards = 0;
    deck->whenEmpty = 0;
    return deck;
}
