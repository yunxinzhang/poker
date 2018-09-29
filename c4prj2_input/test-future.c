#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"
void disp(future_cards_t f){
  printf("%ld deck\n", f.n_decks);
  for(int i=0; i<f.n_decks; ++i){
	for(int j=0; j<f.decks[i].n_cards; ++j){
		printf("%2d-%2d ; ", f.decks[i].cards[j]->value, f.decks[i].cards[j]->suit); 
	}
	printf("\n");
  }
}
int main(){
  // char * filename = "tinput1"; 
  // FILE *f = fopen(filename, "r");
  // if(f==NULL)exit(EXIT_FAILURE);
  // size_t n_hands;
   future_cards_t fc;
   fc.decks = NULL;
   fc.n_decks = 0;
   
   card_t c1 ={.value= 0, .suit=0};
   card_t c2 ={.value= 0, .suit=0};
   card_t c3 ={.value= 0, .suit=0};
   card_t c4 ={.value= 0, .suit=0};
   add_future_card( &fc, 0, &c1 );
   add_future_card( &fc, 1, &c2 );
   add_future_card( &fc, 2, &c3 );
   add_future_card( &fc, 3, &c4 );
   disp(fc);
  card_t c[5];
  c[1].value = 4; c[1].suit = 0;
  c[2].value = 5; c[2].suit = 1;
  c[3].value = 5; c[3].suit = 2;
  c[4].value = 6; c[4].suit = 3;
  c[0].value = 3; c[0].suit = 1;
  deck_t  dk ;
  dk.n_cards = 0;
  dk.cards = NULL;
  add_card_to(&dk, c[0]);
  add_card_to(&dk, c[1]);
  add_card_to(&dk, c[2]);
  add_card_to(&dk, c[3]);
  add_card_to(&dk, c[4]);
   future_cards_from_deck(&dk, &fc);
   disp(fc);
}

