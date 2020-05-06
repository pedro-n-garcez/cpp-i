#include "stdafx.h"
#include "Game.h"
#include "Person.h"
#include "Dealer.h"
#include "Player.h"
#include "Cards.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

Game::Game()
{
	std::cout << "Welcome to Blackjack. You start.\n";
	GetCard(p);
	GetCard(d);
	GetCard(p);
	GetCard(d);
	Hand();
}


Game::~Game()
{
}

void Game::Hand()
{
	//Player loop
	while (p.hitme)
	{
		if (p.sum(p.yourCards) > 21) { break; }
		std::cout << "You have " << p.yourCards.size() << " cards. Their values are:\n";
		for (std::size_t i = 0; i < p.yourCards.size(); ++i) {
			std::cout << p.yourCards[i] << '\n';
		} std::cout << "H for hit, S for stay.\n";
		std::cin >> p.choice;
		std::transform(p.choice.begin(), p.choice.end(), p.choice.begin(), ::toupper);
		if (p.choice == "H") {
			p.hitme = true;
			GetCard(p);
			std::cout << "Your new card is worth " << p.yourCards[p.yourCards.size() - 1] << std::endl;
		}
		else if (p.choice == "S") {
			p.hitme = false;
		}
	}
	//Dealer loop
	while (d.hitme)
	{
		if (p.sum(p.yourCards) > 21 || d.sum(d.yourCards) > 21) { break; }
		if (d.sum(d.yourCards) < 18)
		{
			d.hitme = true;
			std::cout << "\nDealer gets a new card.\n" << std::endl;
			GetCard(d);
		}
		else if (d.sum(d.yourCards) >= 18)
		{
			d.hitme = false;
			std::cout << "\nDealer stays.\n" << std::endl;
		}
	}
	std::cout << "Player sum: " << p.sum(p.yourCards) << "\n";
	std::cout << "Dealer sum: " << d.sum(d.yourCards) << "\n";
	//Victory conditions
	if (p.sum(p.yourCards) > 21)
	{
		std::cout << "YOU LOST. It's a burst!" << std::endl;
	}
	else if (d.sum(d.yourCards) > 21)
	{
		std::cout << "YOU WIN! The dealer bursts!" << std::endl;
	}
	else if (p.sum(p.yourCards) > d.sum(d.yourCards))
	{
		std::cout << "YOU WIN! The dealer loses." << std::endl;
	}
	else if (p.sum(p.yourCards) < d.sum(d.yourCards))
	{
		std::cout << "YOU LOSE! The dealer wins." << std::endl;
	}
	else if (p.sum(p.yourCards) == d.sum(d.yourCards))
	{
		std::cout << "IT'S A DRAW!" << std::endl;
	}
}

void Game::GetCard(Person& p)
{
		//give card from deck
		p.newCard = c1.deck.at(0);
		std::vector<char>::iterator it = c1.deck.begin();
		c1.deck.erase(it);
		//determine the value of the card received
		switch (p.newCard)
		{
		case '2':
			p.yourCards.push_back(2);
			break;
		case '3':
			p.yourCards.push_back(3);
			break;
		case '4':
			p.yourCards.push_back(4);
			break;
		case '5':
			p.yourCards.push_back(5);
			break;
		case '6':
			p.yourCards.push_back(6);
			break;
		case '7':
			p.yourCards.push_back(7);
			break;
		case '8':
			p.yourCards.push_back(8);
			break;
		case '9':
			p.yourCards.push_back(9);
			break;
		case 'T':
			p.yourCards.push_back(10);
			break;
		case 'J':
			p.yourCards.push_back(10);
			break;
		case 'Q':
			p.yourCards.push_back(10);
			break;
		case 'K':
			p.yourCards.push_back(10);
			break;
		case 'A':
			if (p.sum(p.yourCards) > 10)
			{
				p.yourCards.push_back(1);
			}
			else if (p.sum(p.yourCards) <= 10)
			{
				p.yourCards.push_back(11);
			}
			break;
		}
}
