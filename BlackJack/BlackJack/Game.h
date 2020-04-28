#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Dealer.h"
#include "Cards.h"

class Game
{
public:
	int counter;
	Player p;
	Dealer d;
	Cards c1;
	Game();
	~Game();
	void Hand();
	void DealerPlay();
	void GetCard(Person& p);
};

#endif