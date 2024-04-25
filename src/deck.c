#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

bool deck_addCard( Deck *deck, Card card ) {
    if ( !deck ) return false;

    if ( deck->numCards == deck->maxCards ) return false;

    deck->cards[deck->numCards++] = card;
    return true;
}

Deck* deck_initializeStandard() {
    Deck *deck = deck_initializeEmpty( 52 );
    for ( uint i = 0; i < 13; ++i ) {
        for ( uint j = 0; j < 4; ++j ) {
            deck_addCard( deck, ( Card ) { .value = i, .suit = j } );
        }
    }
    return deck;
}