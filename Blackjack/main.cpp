#include "Deck.h"
#include <iostream>
#include "Player.h"
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string newGame;
	Player dealer, player;

	while(true)
	{
		cout << "Player balance is " << player.GetBalance() << "$" << endl;

		while(true) // deciding to play on or leave
		{
			cout << "Play? (y/n)" << endl;
			cin >> newGame;
			cout << endl;

			if (newGame == "y" || newGame == "Y")
				break;
			if (newGame == "n" || newGame == "N")
			{
				system("pause");
				return 0;
			}
			
			cout << "Error! Bad input!" << endl;
		}

		int bet;
		string betString;
		while(true) // betting
		{
			cout << "How much would you like to bet?" << endl;
			cin >> betString;

			int i;// looks for non-digit characters in input
			for (i = 0; betString[i] != '\0' && isdigit(betString[i]); i++); 
			if(!isdigit(betString[i]) && betString[i] != '\0')
			{
					cout << "Invalid bet!" << endl << endl;
			}
			else
			{
				bet = stoi(betString);
				if (bet <= player.GetBalance())
				{
					player.Bet(bet);
					break;
				}
				cout << "Player does not have enough money!" << endl << endl;
			}
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

		bool playerWinFlag = false, dealerWinFlag = false; // case when someone gets a "natural"
		if (player.CountPoints() == 21)
			playerWinFlag = true;
		else if (dealer.CountPoints() == 21)
			dealerWinFlag = true;
			
		string drawCard;
		while (true) // the playing stage
		{
			if (playerWinFlag || dealerWinFlag)
				break;

			cout << "Would you like to draw a card? (y/n)" << endl;
			cin >> drawCard;
			cout << endl;

			if (drawCard == "n" || drawCard == "N")
			{
				cout << "Player stays." << endl << endl;
				break;
			}
			if (drawCard != "y" && drawCard != "Y")
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
				cout << "Player went bust!" << endl << endl;
				break;
			}

			cout << "Player now has:" << endl;
			player.PrintHand();
			cout << endl;
		}

		while(dealer.CountPoints() < 17) // the dealer's move
		{
			if (dealerWinFlag || playerWinFlag)
				break;

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

		int result; // check who won, 0 - draw, 1 - player, 2 - dealer
		
		if (!dealerWinFlag && !playerWinFlag)
		{
			cout << "Dealer stays." << endl << endl;

			const auto playerPoints = player.CountPoints();
			const auto dealerPoints = dealer.CountPoints();

			if (playerPoints > 21 && dealerPoints > 21) // checking for busts
				result = 0;
			else if (dealerPoints > 21)
				result = 1;
			else if (playerPoints > 21)
				result = 2;
			else if (playerPoints < dealerPoints) // checking for equal point cases
				result = 2;
			else if (playerPoints > dealerPoints) // basic cases
				result = 1;
			else
				result = 0;
		}
		else if (playerWinFlag)
			result = 1;
		else
			result = 2;

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
			system("pause");
			return 0;
		}

		player.EmptyHand();
		dealer.EmptyHand();
	} 
}
