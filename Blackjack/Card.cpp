#include "Card.h"
#include <iostream>
#include <string>

Card::Card()
{
	suit = UndefinedSuit;
	rank = UndefinedRank;
}

Card::Card(int rankToSet, int suitToSet)
{
	suit = Suit(suitToSet);
	rank = Rank(rankToSet);
}

Rank Card::GetRank() const
{
	return rank;
}

Suit Card::GetSuit() const
{
	return suit;
}

void Card::Print() const
{
	std::string rankArray[14] = { "Ace", "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	std::string suitArray[4] = { "Spades", "Clubs", "Hearts", "Diamonds" };

	std::cout << rankArray[rank] << " of " << suitArray[suit];
}
