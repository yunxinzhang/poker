#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for(int i=0; i<hand->n_cards; ++i){
    print_card( *(hand->cards[i]) );    
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for(int i=0; i<d->n_cards; ++i){
    if(d->cards[i]->value == c.value && d->cards[i]->suit == c.suit)
	return 1;
  }
  return 0;
}
//#include <time.h>
void shuffle(deck_t * d){
  int rnd = 0;
  card_t * cp = NULL;
//  srand(clock());
  for(int i=0; i<d->n_cards; ++i){
	rnd = random() % (d->n_cards-i) + i;
	cp = d->cards[i];
	d->cards[i] = d->cards[rnd];
	d->cards[rnd] = cp; 
  }
//  cp = NULL;
}

void assert_full_deck(deck_t * d) {
  int nc[52]={0};
//  for(int i=0; i<52; ++i){
//	nc[i]=0;
//	printf("%d",nc[i]);
//  }
  int ind = 0;
  for(int i=0; i<d->n_cards; ++i){
    ind = d->cards[i]->suit * 13 + d->cards[i]->value -2;
    nc[ind]+=1;
//	printf("%d,", ind);    
    if(nc[ind]>1){
	exit(EXIT_FAILURE);
    }
  }
}
