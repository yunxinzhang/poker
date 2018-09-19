#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
	if( c.value < 2 || c.value > 14 || c.suit < 0 || c.suit > 3 )
		printf("Those are not valid values\n");
}

 const char * p0 = "STRAIGHT_FLUSH";
 const char * p1 = "FOUR_OF_A_KIND";
 const char * p2 = "FULL_HOUSE";
 const char * p3 = "FLUSH";
 const char * p4 = "STRAIGHT";
 const char * p5 = "THREE_OF_A_KIND";
 const char * p6 = "TWO_PAIR";
 const char * p7 = "PAIR";
 const char * p8 =  "NOTHING";
const char * ranking_to_string(hand_ranking_t r) {
  switch ((int)r){
    case 0: return p0; 	
    case 1: return p1; 	
    case 2: return p2; 	
    case 3: return p3; 	
    case 4: return p4; 	
    case 5: return p5; 	
    case 6: return p6; 	
    case 7: return p7; 	
    case 8: return p8; 
  }	
  return "";
}

char value_letter(card_t c) {
  switch(c.value){
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return '0';
    case 11: return 'J';
    case 12: return 'Q';
    case 13: return 'K';
    case 14: return 'A';
  }	
  return 'x';

}




char suit_letter(card_t c) {
  switch((int)c.suit){
    case 0:return 's';
    case 1:return 'h';
    case 2:return 'd';
    case 3:return 'c';
  }
  return 'x';
  
}

void print_card(card_t c) {
	printf("%c%c", value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if(value_let>='1' && value_let<='9'){
    temp.value = value_let - '0';
  }else if(value_let == '0'){
    temp.value = 10;
  }else if(value_let == 'J'){
    temp.value = 11;
  }else if(value_let == 'Q'){
    temp.value = 12;
  }else if(value_let == 'K'){
    temp.value = 13;
  }else if(value_let == 'A'){
    temp.value = 14;
  }else {
    temp.value = 15;
    assert_card_valid(temp); exit(EXIT_FAILURE);
  }
  switch (suit_let){
    case ('s') : temp.suit = 0; break;
    case ('h') : temp.suit = 1; break;
    case ('d') : temp.suit = 2; break;
    case ('c') : temp.suit = 3; break;
    default: temp.suit = 4; assert_card_valid(temp); exit(EXIT_FAILURE);
  }
  return temp;

}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c % 13 + 2;
  temp.suit = c / 13;
  return temp;
}
