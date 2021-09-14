
#include "game_blackjack.h"

void Card::Flip() {
  m_IsFaceUp = !(m_IsFaceUp);
}

int Card::GetValue() const {
  int value = 0;
  if (m_IsFaceUp)
  {
    value = m_rank;
    if (value > 10)
    {
      value = 10;
    }
  }
  return value;
}

int Hand::GetTotal() const {
  int sum = 0;
  for(const auto& c: cards)
  {
    if(c->GetRank() == ACE)
      sum += 11;
    else
      sum += c->GetValue();
  }
  for(const auto& c: cards)
    if(c->GetRank() == ACE)
      sum -= 10;
  return sum;
}

void Hand::Clear()
{
  for(auto& pCard: cards)
  {
    delete pCard;
  }
  cards.clear();
}

bool GenericPlayer::IsBoosted() const
{
  if(GetTotal() > 21)
    return true;
  return false;
}

void GenericPlayer::Bust() const
{
  cout << "Player " << name << " gets busted." << endl;
}
