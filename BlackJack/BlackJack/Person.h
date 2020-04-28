#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

class Person
{
public:
	char newCard;
	bool hitme;
	std::vector<int> yourCards;
	int sum(std::vector<int> v);

	Person();
	~Person();
};

#endif