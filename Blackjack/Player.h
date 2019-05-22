#pragma once
#include <vector>
#include "Card.h"

class Player
{
	std::vector<Card> hand;
	int cashBalance;

public:
	Player();
	int CountPoints();
	bool IsBust();
	void DrawCard(Card drawnCard);
	void PrintHand();
	int GetBalance() const;
	void Bet(int bet);
	void Win(int win);
	void EmptyHand();
	int CardsInHand() const;
};
