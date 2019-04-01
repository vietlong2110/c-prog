#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value <= VALUE_ACE && c.value >= 2);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  default: return "NOTHING";
  }
}

char value_letter(card_t c) {
  if (c.value <= 9 && c.value >= 2)
    return '0' + c.value;
  if (c.value == 10)
    return '0';
  switch(c.value) {
  case VALUE_ACE: return 'A';
  case VALUE_KING: return 'K';
  case VALUE_QUEEN: return 'Q';
  default: return 'J';
  }
}


char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  default: return 'c';
  }
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if (value_let >= '2' && value_let <= '9')
    temp.value = value_let - '0';
  if (value_let == '0')
    temp.value = 10;
  if (value_let == 'J')
    temp.value = VALUE_JACK;
  if (value_let == 'Q')
    temp.value = VALUE_QUEEN;
  if (value_let == 'K')
    temp.value = VALUE_KING;
  if (value_let == 'A')
    temp.value = VALUE_ACE;
  if (suit_let == 's')
    temp.suit = SPADES;
  if (suit_let == 'h')
    temp.suit = HEARTS;
  if (suit_let == 'd')
    temp.suit = DIAMONDS;
  if (suit_let == 'c')
    temp.suit = CLUBS;
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c % 13 + 2;
  temp.suit = c / 13;
  assert_card_valid(temp);
  return temp;
}
