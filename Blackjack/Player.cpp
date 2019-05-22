#include "Player.h"
#include <iostream>

Player::Player()
{
	cashBalance = 500;
}

int Player::CountPoints()
{
	auto sum = 0;

	for(auto i = hand.begin(); i != hand.end(); ++i)
	{
		if (i->GetRank() > 9)
			sum += 10;
		else if (i->GetRank() > 0)
			sum += i->GetRank() + 1;
	}

	for (auto i = hand.begin(); i != hand.end(); ++i)
	{
		if(i->GetRank() == 0)
		{
			if (sum + 11 > 21)
				sum += 1;
			else
				sum += 11;
		}
	}

	return sum;
}

bool Player::IsBust()
{
	return(CountPoints() > 21);
}

void Player::DrawCard(Card drawnCard)
{
	hand.push_back(drawnCard);
}

void Player::PrintHand()
{
	for (auto i = hand.begin(); i != hand.end(); ++i)
	{
		i->Print();
		std::cout << "  ";
	}
	std::cout << std::endl;
}

int Player::GetBalance() const
{
	return cashBalance;
}

void Player::Bet(int bet)
{
	cashBalance -= bet;
}

void Player::Win(int win)
{
	cashBalance += win;
}

void Player::EmptyHand()
{
	while (!hand.empty())
		hand.pop_back();
}

int Player::CardsInHand() const
{
	return hand.size();
}
