#include <iostream>
#include "Deck.h"
#include "Cards.h"

using namespace std;

string choice;
double cash = 1000;
double bet = 0;
double pot = 0;
bool errorCheck = false;

bool playerHasPair = false;
bool playerHasTwoPair = false;
bool playerHasFlush = false;
int playerPoints = 0;

bool dealerHasPair = false;
bool dealerHasTwoPair = false;
bool dealerHasFlush = false;
int dealerPoints = 0;

int temp = 0;

void playerBet()
{
	do {
		bet = 0;
		errorCheck = false;
		cout << "Enter your bet (max bet 9999, 0 to call) , you currently have " << cash << " pounds to play with" << endl;
		cin >> bet;


		if (bet > cash)
		{
			cout << "Sorry, you do not have enough money to bet that much" << endl;
			errorCheck = false;
		}
		else if (bet > 9999)
		{
			cout << "Maximum bet exceede, please enter a new bet" << endl;
			errorCheck = false;
		}
		else
		{
			cash = cash - bet;
			pot = pot + bet;
			bet = 0;
			errorCheck = true;
		}

	} while (errorCheck == false);

	
}

int main()
{
	/*deck d;
	card c;

	for (int i = 0; i < 52; i++)
	{
		c = d.dealCard();
		cout << c.DisplayCard() << endl;
	}

	cout << " " << endl;

	d.shuffleDeck();

	for (int i = 0; i < 52; i++)
	{
		c = d.dealCard();
		cout << c.DisplayCard() << endl;
	}*/



	do
	{
		cout << "Enter 1 to play, 2 for instructions or enter x to exit" << endl;
		cin >> choice;

		if (choice == "1")
		{
			pot = 0;
			deck d;

			card playerCardOne = d.dealCard();
			d.shuffleDeck();
			card playerCardTwo = d.dealCard();
			d.shuffleDeck();

			card playerCards[2] = { playerCardOne, playerCardTwo };

			card dealerCardOne = d.dealCard();
			d.shuffleDeck();
			card dealerCardTwo = d.dealCard();
			d.shuffleDeck();

			card dealerCards[2] = { dealerCardOne, dealerCardTwo };

			card poolCardOne = d.dealCard();
			d.shuffleDeck();
			card poolCardTwo = d.dealCard();
			d.shuffleDeck();
			card poolCardThree = d.dealCard();
			d.shuffleDeck();
			card poolCardFour = d.dealCard();
			d.shuffleDeck();
			card poolCardFive = d.dealCard();
			d.shuffleDeck();

			card poolCards[5] = { poolCardOne, poolCardTwo, poolCardThree, poolCardFour, poolCardFive };

			cout << "Your hand is " << playerCards[0].DisplayCard() << " and " << playerCards[1].DisplayCard() << endl;

			playerBet();

			bet = 0;
			cout << "There is currently " << pot << " pounds in the pot" << endl;
			cout << "The first three community cards are " << poolCards[0].DisplayCard() << " , " << poolCards[1].DisplayCard() << " , " << poolCards[2].DisplayCard() << " , " << endl;
			
			playerBet();

			bet = 0;
			cout << "There is currently " << pot << " pounds in the pot" << endl;
			cout << "The next community card is " << poolCards[3].DisplayCard() << endl;

			playerBet();

			bet = 0;
			cout << "There is currently " << pot << " pounds in the pot" << endl;
			cout << "The last community card is " << poolCards[4].DisplayCard() << endl;

			playerBet();

			cout << "The dealer has " + dealerCards[0].DisplayCard() + " and " + dealerCards[1].DisplayCard() << endl;

			temp = 0;

			for (int x = 0; x < 2; x++)
			{
				for (int y = 0; y < 5; y++)
				{
					if (playerCards[x].returnFace() == poolCards[y].returnFace())
					{
						temp = temp + 1;
					}

				}
			}


			if (playerCardOne.returnFace() == playerCardTwo.returnFace())
			{
				temp = temp + 1;
			}

			if (temp == 0)
			{
				playerHasPair = false;
			}
			else if (temp == 1)
			{
				playerHasPair = true;
				playerPoints = 1;
			}
			else 
			{
				playerHasTwoPair = true;
				playerPoints = 2;
			}

			int suitTemp = 0;

			for (int x = 0; x < 2; x++)
			{
				for (int y = 0; y < 5; y++)
				{
					if (playerCards[x].returnSuit() == poolCards[y].returnSuit())
					{
						suitTemp = suitTemp + 1;
					}

				}
			}


			if (playerCardOne.returnFace() == playerCardTwo.returnFace())
			{
				suitTemp = suitTemp + 1;
			}

			if (suitTemp >= 5)
			{
				playerHasFlush = true;
				playerPoints = 3;
			}



			temp = 0;

			for (int x = 0; x < 2; x++)
			{
				for (int y = 0; y < 5; y++)
				{
					if (dealerCards[x].returnFace() == poolCards[y].returnFace())
					{
						temp = temp + 1;
					}

				}
			}


			if (dealerCardOne.returnFace() == dealerCardTwo.returnFace())
			{
				temp = temp + 1;
			}

			if (temp == 0)
			{
				dealerHasPair = false;
			}
			else if (temp == 1)
			{
				dealerHasPair = true;
				dealerPoints = 1;
			}
			else
			{
				dealerHasTwoPair = true;
				dealerPoints = 2;
			}

			suitTemp = 0;

			for (int x = 0; x < 2; x++)
			{
				for (int y = 0; y < 5; y++)
				{
					if (dealerCards[x].returnSuit() == poolCards[y].returnSuit())
					{
						suitTemp = suitTemp + 1;
					}

				}
			}


			if (dealerCardOne.returnFace() == dealerCardTwo.returnFace())
			{
				suitTemp = suitTemp + 1;
			}

			if (suitTemp >= 5)
			{
				dealerHasFlush = true;
				dealerPoints = 3;
			}


			if (playerPoints > dealerPoints)
			{
				cout << "Congratulations! you win " << pot * 2 << endl;
				cash = cash + (pot * 2);
			}
			else if (dealerPoints > playerPoints)
			{
				cout << "Sorry, you loose" << endl;
			}
			else
			{
				cout << "Its a draw!" << endl;
				cash = cash + pot;
			}
		}
		
	else if (choice == "2")
		{
		cout << "This is a basic poker game that checks for pairs and flushes. You play against the dealer. There are four rounds of betting following a simular ruleset to texas hold'em. If you win your total bet is doubled, if you loose you loose your bet" << endl;
		}
		

	} while (choice != "x");


	return 0;
}