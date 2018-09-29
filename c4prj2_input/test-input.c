#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"
int card_ptr_comp2(const void * vp1, const void * vp2) {
  const card_t * const * c1 = (const card_t * const *) vp1;
  const card_t * const * c2 = (const card_t * const *) vp2;
  if( (*c1)->value > (*c2)->value ) 
	return -1;
  else if( (*c1)->value < (*c2)->value ) 
    	return 1;
  else if ( (*c1)->suit > (*c2)->suit)
	return -1;
  else if ( (*c1)->suit < (*c2)->suit )
	return 1;
  return 0;
}
void disp(future_cards_t f){
  printf("%ld deck\n", f.n_decks);
  for(int i=0; i<f.n_decks; ++i){
	for(int j=0; j<f.decks[i].n_cards; ++j){
		printf("%ld\n", f.decks[i].n_cards);
		printf("%2d-%2d ; ", f.decks[i].cards[j]->value, f.decks[i].cards[j]->suit); 
	}
	printf("\n");
  }
}
int main(){
   char * filename = "tinput"; 
   FILE *f = fopen(filename, "r");
   if(f==NULL){
	perror("Open file failed");
	exit(EXIT_FAILURE);
   }
   future_cards_t  fcp ;
   fcp.n_decks = 0;
   fcp.decks = NULL;
   size_t n_hands=0;
   printf("read start");
 deck_t ** allhand =   read_input(f, &n_hands, &fcp);
   //disp(fcp); 
   for(int i=0; i<n_hands; ++i){
	print_hand(allhand[i]);
	printf("\n");
   }
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
   future_cards_from_deck(&dk, &fcp);
   for(int i=0; i<n_hands; ++i){
	print_hand(allhand[i]);
	printf("\n");
  qsort(allhand[i]->cards,allhand[i]->n_cards, sizeof(allhand[i]->cards[0]),  card_ptr_comp2);
	print_hand(allhand[i]);
	printf("\n");
   }
/*
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
*/
}

