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
	Rank GetRank() const;
	Suit GetSuit() const;
	void Print() const;
};