#include "Deck.h"
#include <iostream>
#include "Player.h"

int main()
{
	char newGame;
	Player dealer, player;

	while(true)
	{
		cout << "Player balance is " << player.GetBalance() << "$" << endl;

		while(true) // deciding to play on or leave
		{
			cout << "Next hand? (y/n)" << endl;
			cin >> newGame;
			cout << endl;

			if (newGame == 'y')
				break;
			if (newGame == 'n')
				return 0;
			
			cout << "Error! Bad input!" << endl;
		}

		int bet;
		while(true) // betting
		{
			cout << "How much would you like to bet?" << endl;
			cin >> bet;
			if (bet <= player.GetBalance())
			{
				player.Bet(bet);
				break;
			}

			cout << "Invalid bet!" << endl;
		}

		cout << endl << "Dealer takes a new pack of cards..." << endl; //the beginning stage
		Deck gameDeck;

		cout << "Dealer shuffles..." << endl << endl;
		gameDeck.Shuffle();

		cout << "Dealer gives you: " << endl;
		auto newCard = gameDeck.Draw();
		newCard.Print();
		player.DrawCard(newCard);
		cout << ", ";
		newCard = gameDeck.Draw();
		newCard.Print();
		player.DrawCard(newCard);
		cout << endl << endl;

		cout << "Dealer takes:" << endl;
		newCard = gameDeck.Draw();
		newCard.Print();
		dealer.DrawCard(newCard);
		cout << ", ";
		newCard = gameDeck.Draw();
		newCard.Print();
		dealer.DrawCard(newCard);
		cout << endl << endl;

		char drawCard;

		while (true) // the playing stage
		{
			cout << "Would you like to draw a card? (y/n)" << endl;
			cin >> drawCard;
			cout << endl;

			if (drawCard == 'n')
			{
				cout << "Player stays." << endl << endl;
				break;
			}

			if (drawCard != 'y')
			{
				cout << "Error! Bad input!" << endl;
				continue;
			}
			
			cout << "Dealer gives you: " << endl;
			newCard = gameDeck.Draw();
			newCard.Print();
			player.DrawCard(newCard);
			cout << endl << endl;

			if (player.IsBust())
			{
				cout << "Player went bust!" << endl;
				break;
			}

			cout << "Player now has:" << endl;
			player.PrintHand();
			cout << endl;
		}

		while(dealer.CountPoints() < 17) // the dealer's move
		{
			cout << "Dealer takes: " << endl;
			newCard = gameDeck.Draw();
			newCard.Print();
			dealer.DrawCard(newCard);
			cout << endl << endl;

			if (dealer.IsBust())
			{
				cout << "Dealer went bust!" << endl;
				break;
			}

			cout << "Dealer now has:" << endl;
			dealer.PrintHand();
			cout << endl;
		}

		cout << "Dealer stays." << endl << endl;


		int result; // checking who won, 0 - draw, 1 - player, 2 - dealer
		const auto playerPoints = player.CountPoints();
		const auto dealerPoints = dealer.CountPoints();
		const auto playerCards = player.CardsInHand();
		const auto dealerCards = dealer.CardsInHand();
		
		if (playerPoints > 21 || dealerPoints > 21)
		{
			if (dealerPoints <= 21)
			{
				result = 2;
			}
			else if (playerPoints <= 21)
			{
				result = 1;
			}
			else
			{
				result = 0;
			}
		}
		else if (playerPoints > dealerPoints)
		{
			result = 1;
		}
		else if (playerPoints == dealerPoints)
		{
			if (playerCards < dealerCards)
			{
				result = 1;
			}
			else if (playerCards > dealerCards)
			{
				result = 2;
			}
			else
			{
				result = 0;
			}
		}
		else
		{
			result = 2;
		}

		switch(result)
		{
		case(0):
			cout << "Draw!" << endl << endl;
			player.Win(bet);
			break;
		case(1):
			cout << "Player wins!" << endl << endl;
			player.Win(bet * 2);	
			break;
		case(2):
			cout << "Dealer wins!" << endl << endl;
			break;
		default:
			cout << "Error!" << endl;
		}
			

		cout << "Player points: " << player.CountPoints() << endl;
		cout << "Dealer points: " << dealer.CountPoints() << endl;

		if(!player.GetBalance()) // checking if player is sleeping on the street tonight
		{
			cout << "Game over!" << endl;
			return 0;
		}

		player.EmptyHand();
		dealer.EmptyHand();
	} 
}
