#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Person.h"
#include <string>

//Child class
class Player :
	public Person
{
public:
	std::string choice;
	Player();
	~Player();
};

#endif