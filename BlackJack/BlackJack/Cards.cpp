#include "stdafx.h"
#include "Cards.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <random>


Cards::Cards()
{
	//shuffle deck
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}


Cards::~Cards()
{
}