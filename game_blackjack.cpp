
#include "game_blackjack.h"


void Card::Flip() {
  m_IsFaceUp = !(m_IsFaceUp);
}
int Card::GetValue() const {
  //если карта перевернута лицом вниз, ее значение равно О
  int value = 0;
  if (m_IsFaceUp)
  {
      // значение - это число, указанное на карте
      value = m_rank;
      // значение равно 10 для JACK, QUEEN и KING
      if (value > 10)
      {
          value = 10;
      }
  }
  return value;
}

int Hand::GetValue() const {
  int sum = 0;
  for(const Card* c: cards)
  {
    if(c->GetValueCard() == ACE)
      sum += 11;
    else
      sum += c->GetValue();
  }
  for(const Card* c: cards)
    if(c->GetValueCard() == ACE)
      sum -= 10;
  return sum;
}

void Hand::Clear()
{
  for(Card* pCard: cards)
  {
    delete pCard;
  }
  cards.clear();
}
