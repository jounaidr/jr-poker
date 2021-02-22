#pragma once
#include <string>
#include <iostream>

using namespace std;

class card
{
public:
	card(string PublicFace, string PublicSuit);
	string DisplayCard();
	string returnFace();
	string returnSuit();
	card();
private:
	string face;
	string suit;
};