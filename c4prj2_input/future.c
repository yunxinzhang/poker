#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "future.h"




void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
	if(fc->n_decks==0 && fc->decks==NULL){
		fc->n_decks = 1;
		fc->decks = malloc(sizeof(fc));
		fc->decks[0].n_cards= 0;
		fc->decks[0].cards = NULL;
	}
	size_t didx =  fc->n_decks-1;
	size_t cap = index+1 > fc->decks[didx].n_cards ? index+1 : fc->decks[didx].n_cards;
	if(cap>fc->decks[didx].n_cards){
	  fc->decks[didx].cards = realloc(fc->decks[didx].cards, 	cap *sizeof(fc));
	  fc->decks[didx].n_cards = cap;
	  for(int i=fc->decks[didx].n_cards; i<cap; ++i){
	     fc->decks[didx].cards[index] = NULL;
 	  }
	}
	fc->decks[didx].cards[index] = ptr;
} 
void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
   	for(int i=0; i<fc->n_decks; ++i){
	  for(int j=0; j<fc->decks[i].n_cards; ++j){
	 	if(fc->decks[i].cards[j] != NULL){
			*(fc->decks[i].cards[j]) = *(deck->cards[j]);
		} 
	  }
 	}


}
