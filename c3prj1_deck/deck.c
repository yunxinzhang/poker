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

void add_card_to(deck_t * deck, card_t c){
  assert(deck != NULL);
  deck->cards = realloc( deck->cards, (deck->n_cards+1) *sizeof(*(deck->cards)));  
  deck->cards[deck->n_cards] = malloc(sizeof( *(deck->cards[deck->n_cards])));
  *(deck->cards[deck->n_cards]) = c;
  ++(deck->n_cards);
}

card_t * add_empty_card(deck_t * deck){
  card_t c = {.suit=0, .value=0};
  add_card_to(deck, c);
  return deck->cards[deck->n_cards-1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
	int sz = 52 - excluded_cards->n_cards;
//	printf("sz = %d\n", sz);
	deck_t * dk = malloc(sizeof(deck_t));
	dk->n_cards = 0;
//	printf("%ld\n", sz*sizeof(excluded_cards));
	dk->cards = malloc(sz *sizeof( excluded_cards ));
	for(size_t i=0; i<52; ++i){
		card_t ci = card_from_num(i);
		if(deck_contains(excluded_cards, ci))continue;
//		assert(dk->n_cards < sz);
//		printf("%ld\n", dk->n_cards);
		dk->cards[dk->n_cards] = malloc(sizeof(card_t));
		*(dk->cards[dk->n_cards++]) = ci;
//		printf("%ld\n", dk->n_cards);
   	}	
//       	printf("make_dekc");
	printf("sz>>%d -- %ld\n", sz, dk->n_cards);
// Has the same cards ,, not allowed.
	assert(dk->n_cards == sz);
	return dk;
}
void free_deck(deck_t * deck){
	for(size_t i=0; i<deck->n_cards; ++i){
		free(deck->cards[i]);
	}
	free(deck->cards);
	free(deck);
} 
deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
	deck_t * ex = malloc(sizeof(deck_t));
	ex->cards = NULL;
	ex->n_cards = 0;
	for(size_t i=0; i<n_hands; ++i){
		for(size_t j=0; j<hands[i]->n_cards; ++j){
			if(hands[i]->cards[j]->suit==0 && hands[i]->cards[j]->value==0){
		perror("deck contain ?"); exit(EXIT_FAILURE);
      }
			add_card_to(ex, *( hands[i]->cards[j]));
		}
	}
	return make_deck_exclude(ex);
} 
