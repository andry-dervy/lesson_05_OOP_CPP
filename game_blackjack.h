#ifndef GAME_BLACKJACK_H
#define GAME_BLACKJACK_H

#include <QCoreApplication>

using namespace std;

enum _rank {
  ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
  JACK, QUEEN, KING
};
enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card
{
private:
  suit m_suit;
  _rank m_rank;
  bool m_IsFaceUp;
public:
  Card(suit aSuit = HEARTS,_rank aRank = TWO, bool aIsFaceUp = false)
    :m_suit(aSuit),m_rank(aRank),m_IsFaceUp(aIsFaceUp){}
  ~Card(){}
  void Flip();
  int GetValue() const;
  _rank GetRank() const {return m_rank;}
};

class Hand
{
private:
  vector<Card*> cards;
public:
  Hand(){}
  virtual ~Hand(){}

  void Add(Card *card){cards.push_back(card);}
  void Clear();
  int GetTotal() const;
};


#endif // GAME_BLACKJACK_H
