#include <stdio.h>
#include "deck.h"
#include "future.h"
#include "input.h"
#include <string.h>
#include <assert.h>
deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t * dt = malloc(sizeof(deck_t));
  dt->n_cards = 0;
  dt->cards = NULL;
  int cnt_cards = 0;
  for(size_t i=0; i<strlen(str); ){
	if( (str[i]>='0'&& str[i]<='9') || (str[i]>='A' && str[i]<='Z') || str[i] == '?'){
		if(str[i] != '?'){
			//printf("%c\n", str[i+1]);
			assert(str[i+1]=='s' || str[i+1] =='d' || str[i+1] =='h' ||str[i+1]=='c');
			add_card_to(dt, card_from_letters(str[i],str[i+1]));
			++cnt_cards;
			i += 2;	
		}else{
			card_t *cp = add_empty_card(dt);
			++cnt_cards;
			assert(i+1<strlen(str));
			if(i+2>=strlen(str) || (str[i+2]>'9' || str[i+2] <'0')){
				add_future_card(fc, atoi(&str[i+1]), cp); 
				i+=2;		
			}else if(i+2<strlen(str)&&str[i+2]<='9' &&str[i+2]>='0') {
				add_future_card(fc, atoi(&str[i+1]), cp);	
				i+=3;		
			}
		}
	
	}else{++i;}
  }
	if(cnt_cards<5)return NULL;
  return dt;
}
deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
	char *line = NULL;
	size_t sz = 0;
	deck_t ** dpp = NULL;
	size_t cnt_hand = 0;
	assert(fc!=NULL && fc->n_decks==0);
	while( getline(&line, &sz, f)!=-1){
		if(strlen(line) > 13){
			fc->n_decks++;
			fc->decks = realloc(fc->decks, fc->n_decks * sizeof(deck_t));
			//printf("%ld <<ndecks<<< %ld\n", fc->n_decks, sizeof(deck_t));
			fc->decks[fc->n_decks-1].n_cards=0;
			fc->decks[fc->n_decks-1].cards=NULL;
			//printf("\n--------2-------\n");
			deck_t *dp = hand_from_string(line, fc);
			cnt_hand++;
			//printf("\n--------3-------\n");
			
			dpp = realloc(dpp, cnt_hand * sizeof(f)); // size of memeryo;
			//printf("%ld <<nhand<<< %ld\n", cnt_hand, sizeof(f));
			//printf("\n--------4-------\n");
			dpp[cnt_hand-1] = dp;
		}
	}
	*n_hands = cnt_hand;
	return dpp;
}

