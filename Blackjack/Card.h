#pragma once
#include "Rank.h"
#include "Suit.h"

class Card
{		
	Rank rank;
	Suit suit;

public:
	Card();
	Card(int rank, int suit);
	void SetRank(int rank);
	void SetSuit(int suit);
	Rank GetRank();
	Suit GetSuit();
	void Print();
};