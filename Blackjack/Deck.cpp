#include "Deck.h"
#include <random>
#include <ctime>

Deck::Deck()
{
	for(auto i = 0; i < 4; i++)
		for(auto j = 0; j < 13; j++)
			cards.push_back(*new Card(j, i));
}

void Deck::Shuffle()
{
	Card tmpDeck[52];
	srand(time(nullptr));

	while(!cards.empty())
	{
		const auto randomIndex = rand() % 52;
		if (tmpDeck[randomIndex].GetRank() == UndefinedRank)
		{
			tmpDeck[randomIndex] = cards.back();
			cards.pop_back();
		}	
	}

	for(auto i = 0; i < 52; i++)
	{
		cards.push_back(tmpDeck[i]);
	}
}

Card Deck::Draw()
{
	const auto cardToDraw = cards.back();
	cards.pop_back();
	return cardToDraw;
}
