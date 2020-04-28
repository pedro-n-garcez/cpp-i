#include "stdafx.h"
#include "Cards.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>


Cards::Cards()
{
	std::srand(time(0));
	std::random_shuffle(deck.begin(), deck.end());
}


Cards::~Cards()
{
}