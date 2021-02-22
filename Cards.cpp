#include "Cards.h"

card::card()
{

}

card::card(string PublicFace, string PublicSuit)
{
	face = PublicFace;
	suit = PublicSuit;
}

string card::DisplayCard()
{
	return (face + " of " + suit);
}

string card::returnFace()
{
	return face;
}

string card::returnSuit()
{
	return suit;
}