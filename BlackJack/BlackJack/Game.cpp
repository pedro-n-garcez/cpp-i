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
	counter = 0;
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
	while (p.hitme == true)
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
	while (d.hitme == true) 
	{
		if (p.sum(p.yourCards) > 21 || d.sum(d.yourCards) > 21) { break; }
		DealerPlay();
	}
	std::cout << "Player sum: " << p.sum(p.yourCards) << "\n";
	std::cout << "Dealer sum: " << d.sum(d.yourCards) << "\n";
	if (p.sum(p.yourCards) > 21)
	{
		std::cout << "Burst! YOU LOSE! And the dealer wins." << std::endl;
	}
	else if (d.sum(d.yourCards) > 21)
	{
		std::cout << "Burst! YOU WIN! And the dealer loses!" << std::endl;
	}
	else if (p.sum(p.yourCards) > d.sum(d.yourCards))
	{
		std::cout << "YOU WIN! And the dealer loses!" << std::endl;
	}
	else if (p.sum(p.yourCards) < d.sum(d.yourCards))
	{
		std::cout << "YOU LOSE! And the dealer wins." << std::endl;
	}
	else if (p.sum(p.yourCards) == d.sum(d.yourCards))
	{
		std::cout << "IT'S A DRAW!" << std::endl;
	} 
}
void Game::DealerPlay()
{
	if (d.sum(d.yourCards) < 18)
	{
		d.hitme = true;
		std::cout << "\nDealer gets a new card.\n\n";
		GetCard(d);
	}
	else if (d.sum(d.yourCards) >= 18)
	{
		d.hitme = false;
		std::cout << "\nDealer stays.\n\n";
	}
}
void Game::GetCard(Person& p)
{
	//std::cout << "DEBUG GETCARD\n";
	//std::cout << counter << " CARD: " << c1.deck[counter] << " IN YOUR DECK: " << p.newCard << "\n";
	p.newCard = c1.deck[counter];
	//std::cout << "NOW IN YOUR DECK: " << p.newCard << std::endl;
	switch (p.newCard)
	{
	case '2':
		p.yourCards.push_back(2);
		counter++;
		break;
	case '3':
		p.yourCards.push_back(3);
		counter++;
		break;
	case '4':
		p.yourCards.push_back(4);
		counter++;
		break;
	case '5':
		p.yourCards.push_back(5);
		counter++;
		break;
	case '6':
		p.yourCards.push_back(6);
		counter++;
		break;
	case '7':
		p.yourCards.push_back(7);
		counter++;
		break;
	case '8':
		p.yourCards.push_back(8);
		counter++;
		break;
	case '9':
		p.yourCards.push_back(9);
		counter++;
		break;
	case 'T':
		p.yourCards.push_back(10);
		counter++;
		break;
	case 'J':
		p.yourCards.push_back(10);
		counter++;
		break;
	case 'Q':
		p.yourCards.push_back(10);
		counter++;
		break;
	case 'K':
		p.yourCards.push_back(10);
		counter++;
		break;
	case 'A':
		if (p.sum(p.yourCards) >= 10)
		{
			p.yourCards.push_back(1);
		}
		else if (p.sum(p.yourCards) < 10)
		{
			p.yourCards.push_back(11);
		}
		counter++;
		break;
	}
}
