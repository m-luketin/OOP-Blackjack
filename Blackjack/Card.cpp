#include "Card.h"
#include <iostream>
#include <string>

Card::Card()
{
	suit = UndefinedSuit;
	rank = UndefinedRank;
}

void Card::SetSuit(int suitToSet)
{
	suit = Suit(suitToSet);
}

void Card::SetRank(int rankToSet)
{
	rank = Rank(rankToSet);
}

Card::Card(int rank, int suit)
{
	SetSuit(suit);
	SetRank(rank);
}

Rank Card::GetRank()
{
	return rank;
}

Suit Card::GetSuit()
{
	return suit;
}

void Card::Print()
{
	std::string rankArray[14] = { "Ace", "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	std::string suitArray[4] = { "Spades", "Clubs", "Hearts", "Diamonds" };

	std::cout << rankArray[rank] << " of " << suitArray[suit];
}
