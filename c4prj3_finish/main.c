#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"
#include <string.h>
int getNum(int n){
	int k = 1;
	for(int i=0; i<n; ++i){
		k *= 10;
	}
	return k;
}
int main(int argc, char ** argv) {
  //YOUR CODE GOES HERE
  int mn=0;
  if(argc==2){
	mn = 10000;
  }else if(argc==3){
//	printf("%s  %ld\n", argv[2], strlen(argv[2]));
	for(int i=0; i<strlen(argv[2]); ++i){
		if(argv[2][i]>'9' || argv[2][i] <'0'){
			perror("not a number");
			exit(EXIT_FAILURE);
		}
//		printf( "%d %d %d\n", mn, getNum(i), argv[2][i]-'0');
	        mn += (argv[2][i]-'0')* getNum(strlen(argv[2])-1-i);
	}
	
  }else{
	perror("wrong args");
	exit(EXIT_FAILURE);
  }
//	printf("%d \n ", mn);
// read_input 
   FILE *f = fopen(argv[1], "r");
   if(f==NULL){
	perror("Open file failed");
	exit(EXIT_FAILURE);
   }
   future_cards_t  fcp ;
   fcp.n_decks = 0;
   fcp.decks = NULL;
   size_t n_hands=0;
   deck_t ** allhand =   read_input(f, &n_hands, &fcp);
   fclose(f);
// remain cards
   deck_t * remain = build_remaining_deck(allhand,n_hands);
   int * cnt_wins = malloc( (n_hands+1) * sizeof(int));
   for(int i=0; i<= n_hands; ++i) cnt_wins[i] = 0;
//	printf("%d \n ", mn);
   for(int i=0; i<mn; ++i){
	shuffle(remain);
	future_cards_from_deck(remain, &fcp);
	deck_t * maxhand = allhand[0];
	int idx_max =0;
	int max_cnt =1;
	for(int j=1; j<n_hands; ++j){
	   if(compare_hands(allhand[j],maxhand)>0){
		maxhand = allhand[j];
		idx_max = j;
		max_cnt =1;
	   }else if(compare_hands(allhand[j],maxhand)==0){
		max_cnt++;
	   }
	}
	if(max_cnt >1)
		cnt_wins[n_hands]++;
	else 
		cnt_wins[idx_max]++;
   }	
   for(int i=0; i<n_hands; ++i){
	printf("Hand %d won %u / %u times (%.2f%%)\n", i, cnt_wins[i], mn, 100.0*cnt_wins[i]/mn);
   }

   printf("And there were %u ties\n", cnt_wins[n_hands]);
   free(cnt_wins);
   for(int i=0; i<n_hands; ++i)
  	 free(allhand[i]);
   free(allhand);

  return EXIT_SUCCESS;
}
