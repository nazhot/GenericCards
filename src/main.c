#include "deck.h"
#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[] ) {
    Deck *deck = deck_initializeStandard();
    deck_print( deck );
    deck_shuffle( deck );
    deck_print( deck );
    return 0;
}
