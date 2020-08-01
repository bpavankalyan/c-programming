#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"



void print_hand(deck_t * hand)
{
  card_t **card=hand->cards;
  int n=hand->n_cards;
  for(size_t i=0;i<n;i++)
  {
    print_card(**(card+i));    
  }

  
}

int compare(card_t c,card_t c1)
{
  if((c1.value==c.value)&& (c1.suit==c.suit))
    return 1;
  return 0;
    }


int deck_contains(deck_t * d, card_t c)
{
  card_t **card=d->cards;
  for(size_t i=0;i<d->n_cards;i++)
    if(compare(**(card+i),c))
       return 1;
       return 0;
}

void shuffle(deck_t * d){

  card_t **card=d->cards;
  card_t *temp;
  int n=d->n_cards;
  int ra;
  for(size_t i=0;i<n/2;i++)
    {
      ra=random()%(n-i)+i;
      temp=card[i];
      card[i]=card[ra];
      card[ra]=temp;
    }
}

void assert_full_deck(deck_t * d) {
  card_t ** card=d->cards;
  int c=0;
  int n=d->n_cards;
  for(size_t i=0;i<n;i++)
    {
      c=0;
      for(size_t j=i+1;j<n;j++)
	if(compare(**(card+i),**(card+j)))
	   c++;
	   assert(c==1);
    }
}
