#pragma once
#include "Card.h"
#include <vector>

using namespace std;

class Deck
{
	vector<Card> cards;

public:
	Deck();
	void Shuffle();
	Card Draw();
};
