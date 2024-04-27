#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

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

void deck_print( Deck *deck ) {
    static const char values[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9',
                            'T', 'J', 'Q', 'K'};
    static const char suits[] = {'D', 'C', 'H', 'S'};

    printf( "Max size: %u\n", deck->maxCards );
    printf( "Num cards: %u\n", deck->numCards );
    for ( uint i = 0; i < deck->numCards; ++i ) {
        printf( "%u: %c%c\n", i, values[deck->cards[i].value], suits[deck->cards[i].suit] );
    }
}

void deck_shuffle( Deck *deck ) {
    if ( !deck->numCards ) return;
    for ( uint i = deck->numCards - 1; i >= 1; --i ) {
        uint j = drand48() * ( i + 1 ); //+1 because conversion from double to uint will just chop off decimal part, and drand48 will always be less than 1
        assert( j <= i );
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

Card deck_popFromStart( Deck *deck ) {
    if ( deck->numCards == 0 ) return ( Card ) {0};
    Card temp = deck->cards[0];
    for ( uint i = 1; i < deck->numCards; ++i ) {
        deck->cards[i - 1] = deck->cards[i];
    }
    --deck->numCards;

    return temp;
}
Card deck_popFromEnd( Deck *deck ) {
    if ( deck->numCards == 0 ) return ( Card ) {0};
    return deck->cards[--deck->numCards];
}

void deck_transferNCardsFromStart( Deck *dest, Deck *src, const uint numCards ) {
    if ( numCards > ( dest->maxCards - dest->numCards ) ) {
        fprintf( stderr, "Not enough room left in dest to transfer cards:\nRoom Left: %u, Num Cards to Add: %u\n", dest->maxCards - dest->numCards, numCards );
        return;
    }
    if ( numCards > src->numCards ) {
        fprintf( stderr, "Not enough cards in source to transfer:\nCards in Source: %u, Num Cards to Add: %u\n", src->numCards, dest->maxCards - dest->numCards );
        return;
    }
    for ( uint i = 0; i < numCards; ++i ) {
        deck_addCard( dest, deck_popFromStart( src ) );
    }
}
void deck_transferNCardsFromEnd( Deck *dest, Deck *src, const uint numCards ) {
    if ( numCards > ( dest->maxCards - dest->numCards ) ) {
        fprintf( stderr, "Not enough room left in dest to transfer cards:\nRoom Left: %u, Num Cards to Add: %u\n", dest->maxCards - dest->numCards, numCards );
        return;
    }
    if ( numCards > src->numCards ) {
        fprintf( stderr, "Not enough cards in source to transfer:\nCards in Source: %u, Num Cards to Add: %u\n", src->numCards, dest->maxCards - dest->numCards );
        return;
    }
    for( uint i = 0; i < numCards; ++i ) {
        deck_addCard( dest, deck_popFromEnd( src )  );
    }
}
void deck_transferAllCards( Deck *dest, Deck *src ) {
    if ( src->numCards > ( dest->maxCards - dest->numCards ) ) {
        fprintf( stderr, "Not enough room left in dest to transfer cards:\nRoom Left: %u, Num Cards to Add: %u\n", dest->maxCards - dest->numCards, src->numCards );
        return;
    }
    uint numCards = src->numCards;
    for( uint i = 0; i < numCards; ++i ) {
        deck_addCard( dest, deck_popFromEnd( src )  );
    }
}
void deck_empty( Deck *deck ) {
    deck->numCards = 0;
}
