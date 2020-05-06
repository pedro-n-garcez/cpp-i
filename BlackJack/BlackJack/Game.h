#pragma once
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Dealer.h"
#include "Cards.h"

class Game
{
private:
	Player p;
	Dealer d;
	Cards c1;
	void Hand();
	void GetCard(Person& p);
public:
	Game();
	~Game();
};

#endif