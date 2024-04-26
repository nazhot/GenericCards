#include "deck.h"
#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[] ) {
    Deck *deck = deck_initializeStandard();
    Deck *deck2 = deck_initializeEmpty( 52 );
    deck_transferNCardsFromEnd( deck2, deck, 3 );
    deck_transferNCardsFromStart( deck2, deck, 3 );
    deck_transferAllCards( deck2, deck );
    deck_print( deck );
    deck_print( deck2 );
    return 0;
}
