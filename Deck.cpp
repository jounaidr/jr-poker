#include "Deck.h"
#include <cstdlib>
#include <ctime>

deck::deck()
{
	string face[] = { "Ace", "Two", "Three", "Four","Five","Six" ,"Seven" ,"Eight" ,"Nine" ,"Ten" ,"Jack" ,"Queen" ,"King" };
	string suit[] = {"Hearts", "Diamonds","Clubs","Spades"};
	decks = new card[cardsPerDeck];
	currentCard = 0;
	for (int i = 0; i < cardsPerDeck; i++)
	{
		decks[i] = card(face[i % 13], suit[i / 13]);
	}
}

void deck::shuffleDeck()
{
	currentCard = 0;
	for (int i = 0; i < cardsPerDeck; i++)
	{
		int next = (rand() + time(0)) % cardsPerDeck;
		card temp = decks[i];
		decks[i] = decks[next];
		decks[next] = temp;
	}
}

card deck::dealCard()
{
	if (currentCard > cardsPerDeck)
	{
		shuffleDeck();
	}
	if (currentCard < cardsPerDeck)
	{
		return (decks[currentCard++]);
	}
	else
	{
		return (decks[0]);
	}
}