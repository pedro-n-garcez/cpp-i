#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

//base class
class Person
{
public:
	char newCard;
	bool hitme; //whether person still wants to hit
	std::vector<int> yourCards;
	int sum(std::vector<int> v);

	Person();
	~Person();
};

#endif