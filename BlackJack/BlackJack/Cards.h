#pragma once
#ifndef CARDS_H
#define CARDS_H
#include <cstdlib>
#include <ctime>
#include <vector>

class Cards
{
public:
	std::vector<char> deck = {
		'2','2','2','2',
		'3','3','3','3',
		'4','4','4','4',
		'5','5','5','5',
		'6','6','6','6',
		'7','7','7','7',
		'8','8','8','8',
		'9','9','9','9',
		'T','T','T','T',
		'J','J','J','J',
		'Q','Q','Q','Q',
		'K','K','K','K',
		'A','A','A','A'
	};
	Cards();
	~Cards();
};

#endif