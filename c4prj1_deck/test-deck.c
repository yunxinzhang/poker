#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"


int main(){

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
//  add_empty_card(&dk); 
//  deck_t *d2 = make_deck_exclude(&dk);
  print_hand(&dk);  
  printf("\n");
//  print_hand(d2);
  unsigned * ss = get_match_counts( &dk );
  for(int i=0; i<dk.n_cards; ++i){

	printf("%5d", ss[i]);
  }
  printf("\n");
  printf("----------------------\n");

  card_t c2[3];
  c2[1].value = 9; c2[1].suit = 0;
  c2[2].value = 10; c2[2].suit = 1;
  c2[0].value = 11; c2[0].suit = 1;
  deck_t  dk2 ;
  dk2.n_cards = 0;
  dk2.cards = NULL;
  printf("dk2 %p\n", &dk2);
  add_card_to(&dk2, c2[0]);
  add_card_to(&dk2, c2[1]);
  add_card_to(&dk2, c2[2]);
  print_hand(&dk2);  
  
  printf("----------------------\n");
  deck_t * hands[2] = {&dk, &dk2};
  deck_t * dk3 = build_remaining_deck(hands, 2);
  printf("\n");
  print_hand(dk3);
}
