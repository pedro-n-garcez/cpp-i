#include "stdafx.h"
#include "Person.h"
#include <vector>


int Person::sum(std::vector<int> v)
{
	int x = 0;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		x += *it;
	return x;
}

Person::Person()
{
	hitme = true;
}


Person::~Person()
{
}
