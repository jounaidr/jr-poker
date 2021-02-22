#pragma once
#include "Cards.h"

using namespace std;

const int cardsPerDeck = 52;

class deck
{
public:
	deck();
	void shuffleDeck();
	card dealCard();
private:
	card *decks;
	int currentCard;
};
