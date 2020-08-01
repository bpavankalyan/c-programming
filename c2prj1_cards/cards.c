
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.suit>=SPADES && c.suit<=CLUBS );
  assert(c.value >=2 && c.value<=VALUE_ACE);
}

const char * ranking_to_string(hand_ranking_t r) {

  if(r==STRAIGHT_FLUSH) return "STRAIGHT_FLUSH";
  else if(r==FOUR_OF_A_KIND) return "FOUR_OF_A_KIND";
  else if(r==FULL_HOUSE) return "FULL_HOUSE";
  else if(r==FLUSH)  return "FLUSH";
  else if(r==STRAIGHT)  return "STRAIGHT";
  else if(r==THREE_OF_A_KIND)  return "THREE_OF_A_KIND";
  else if(r==TWO_PAIR)  return "TWO_PAIR";
  else if(r== PAIR)  return "PAIR";
  else if(r==NOTHING)  return "NOTHING";
  else  return "???";
}


char value_letter(card_t c) {
  switch(c.value) {
  case 2: return '2'; break;
  case 3: return '3'; break;
  case 4: return '4'; break;
  case 5: return '5'; break;
  case 6: return '6'; break;
  case 7: return '7'; break;
  case 8: return '8'; break;
  case 9: return '9'; break;
  case 10: return '0'; break;
  case VALUE_JACK : return 'J'; break;
  case VALUE_QUEEN : return'Q'; break;
  case VALUE_KING : return 'K'; break;
  case VALUE_ACE : return 'A'; break;
  default : return '?'; break;
  }
}


char suit_letter(card_t c) {  if(c.suit== SPADES) return 's';
  else  if(c.suit==  HEARTS) return 'h';
  else  if(c.suit== DIAMONDS) return 'd';
  else  if(c.suit== CLUBS) return 'c';
  else  return '?';
}

void print_card(card_t c) {
  char t,l;
  t=value_letter(c);
  l=suit_letter(c);
  printf("%c%c",t,l);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let) {
  case   '2': temp.value =  2; break;
  case   '3': temp.value =  3; break;
  case   '4': temp.value =  4; break;
  case   '5': temp.value =  5; break;
  case   '6': temp.value =  6; break;
  case   '7': temp.value =  7; break;
  case   '8': temp.value =  8; break;
  case   '9': temp.value =  9; break;
  case   '0': temp.value =  10; break;
  case  'J' :temp.value = VALUE_JACK ; break;
  case 'Q' : temp.value = VALUE_QUEEN ; break;
  case 'K' :temp.value = VALUE_KING ; break;
  case 'A' :temp.value=VALUE_ACE ; break;
  }
  if(suit_let=='s') temp.suit= SPADES;
  if(suit_let=='h') temp.suit=  HEARTS;
  if(suit_let=='d') temp.suit= DIAMONDS;
  if(suit_let=='c') temp.suit= CLUBS;
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value=c/4 + 2;
  temp.suit= c%4;
  return temp;
}



/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  int cond1,cond2;
  cond1=(c.value >=2 )&&(c.value <= VALUE_ACE);
  cond2=(c.suit ==  SPADES )||(c.suit == CLUBS )||(c.suit ==  HEARTS)||(c.suit == DIAMONDS);
  assert(cond1 && cond2);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r){
  case  STRAIGHT_FLUSH:  return "STRAIGHT_FLUSH";
  case  FOUR_OF_A_KIND: return"FOUR_OF_A_KIND";
  case FULL_HOUSE: return"FULL_HOUSE";
  case  FLUSH: return"FLUSH";
  case  STRAIGHT: return"STRAIGHT";
  case  THREE_OF_A_KIND: return"THREE_OF_A_KIND";
  case  TWO_PAIR: return"TWO_PAIR";
  case  PAIR: return"PAIR";
  default  : return"NOTHING";
  }
}

char value_letter(card_t c) {
  char x='?';
  if ((c.value >= 2 )&&( c.value <=9)) x = '0' + c.value ;
  else {
    switch(c.value){
    case VALUE_KING : {x='K';  break;}
    case 10 : {   x='0';  break;}
    case VALUE_ACE :{ x= 'A' ;  break;}
    case VALUE_QUEEN :{x='Q' ; break;}
    case VALUE_JACK :{x='J' ; break;}
    default :break;
    }
  }
  return x ;
}


char suit_letter(card_t c) {
  char x='?';
  switch(c.suit){
  case  SPADES : {x='s';  break;}
  case HEARTS : {   x='h';  break;}
  case DIAMONDS :{ x= 'd' ;  break;}
  case CLUBS :{x='c' ; break;}
  default :{ x='N'; break;}
  }
  return x;

}

void print_card(card_t c) {
  char suit1= suit_letter( c);
  char value1= value_letter( c);
  printf("%c%c ",value1,suit1);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case 'K' : {temp.value= 13;  break;}
  case '0' : { temp.value= 10;  break;}
  case 'A' :{ temp.value= 14;  break;}
  case 'Q' :{temp.value= 12; break;}
  case 'J' :{temp.value= 11; break;}
  default :{temp.value=value_let - '0';
      break;} }

  switch(suit_let){
  case  's'  : {temp.suit =SPADES;  break;}
  case 'h' : {  temp.suit =HEARTS;  break;}
  case 'd' :{temp.suit = DIAMONDS ;  break;}
  case  'c':{temp.suit =CLUBS ; break;}
  default: {temp.suit = NUM_SUITS;  break; }}
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  unsigned value = c%13 + 2;
  temp.value = value;

  unsigned suit = c/13;
  switch(suit){
  case  0 : {temp.suit =SPADES;  break;}
  case 1 : {  temp.suit =HEARTS;  break;}
  case 2 :{temp.suit = DIAMONDS ;  break;}
  case 3:{temp.suit =CLUBS ; break;}
  default: {temp.suit = NUM_SUITS;  break; }}

  return temp;

}

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"
void assert_card_valid(card_t c) {
}
const char * ranking_to_string(hand_ranking_t r) {
  return "";
}
char value_letter(card_t c) {
  return 'x';
}
char suit_letter(card_t c) {
  return 'x';
  
}
void print_card(card_t c) {
}
card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  return temp;
}
card_t card_from_num(unsigned c) {
  card_t temp;
  return temp;
}
*/
